```
 /$$   /$$           /$$ /$$                          
| $$  /$$/          | $$| $$                          
| $$ /$$/   /$$$$$$ | $$| $$  /$$$$$$   /$$$$$$       
| $$$$$/   /$$__  $$| $$| $$ /$$__  $$ /$$__  $$      
| $$  $$  | $$$$$$$$| $$| $$| $$  \ $$| $$  \ $$      
| $$\  $$ | $$_____/| $$| $$| $$  | $$| $$  | $$      
| $$ \  $$|  $$$$$$$| $$| $$|  $$$$$$/|  $$$$$$$      
|__/  \__/ \_______/|__/|__/ \______/  \____  $$      
                                       /$$  \ $$      
                                      |  $$$$$$/      
                                       \______/      
```
# Kellog
Kellog is a RAT (Remote Access Trojan) with Keylogging functionality.
This project is to be used for DEMONSTRATION PURPOSES ONLY. I AM NOT RESPONSIBLE FOR ANY MISUSE OF THIS PRODUCT

Kellog poses as a fake "game cracker" which would unlock the secret game "frosted flakes" (there is no affiliation)
But in reality the user is executing a reverse shell & creating a hidden file called "dependencies"

# The Basics:
When run a hidden file called ".dependencies" will be created in the same directory kellog.exe is in.
This file holds the keylogging functionality.
At the same time the attacker should have a nc listener on the configured port, for ex. nc -lvnp 1234
Since (in our demonstration) we will run Kellog with admin privileges the attacker should receive a admin powershell.

Kellog will continue to run in the background, to stop go to task manager and find "kellog.exe" and end the task.
Make sure to delete the hidden "dependencies" file!

# TO COMPILE:

LINUX
    i686-w64-mingw32-g++ -static-libstdc++ -static-libgcc -o kellog.exe Kellog.c -lsw2_32 -DUNICODE

WINDOWS
    g++ -o kellog.exe kellog.cpp -lws2_32 -DUNICODE

# The Purpose of this Project
Kellog is simply my own malware example that will be used for a live in class presentation on reverse engineering.
Kellog is not made to be advanced, on the contrary it's meant to be very simple.  
