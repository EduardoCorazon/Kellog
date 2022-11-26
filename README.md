# Kellog
This is a remote keylogger coded in C, used for demonstration purposes


# TO COMPILE:

# LINUX
i686-w64-mingw32-g++ -static-libstdc++ -static-libgcc -o kellog.exe Kellog.c -lsw2_32 -DUNICODE

# WINDOWS
g++ -o kellog.exe kellog.cpp -lws2_32 -DUNICODE

# HOW TO USE
deploy Kellog.exe and run it
  - it should automatically run as a background service called "kellog
