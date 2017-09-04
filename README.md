# countdown
This is a simple command-line game based on the game show _Countdown_.
I wrote it as project which went towards my final mark in the Programming module in First Year.

Originally it was only one file, countdown.c, but for uploading it to GitHub I have split it into header and source files.
As I split it up, I also used the command line to compile it instead of Visual Studio, so references to `"stdafx.h"` have been removed.

Note that the webster.txt file, which provides the list of valid words, must be in the same directory or folder as the final executable file.

## Command-line compilation

### Visual C
    cl main.c countdown.c /link /out:countdown.exe

### GCC
    gcc main.c countdown.c -o countdown

### Clang
    clang main.c countdown.c -o countdown
