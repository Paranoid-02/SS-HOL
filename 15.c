/*
============================================================================
Name : 15.c
Author : Akshay Sharma
Description : Write a program to display the environmental variable of the user(use environ).
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    extern char **environ; // Declare the environ array

    for (char **env = environ; *env != NULL; ++env)
    {
        printf("%s\n", *env);
    }

    return 0;
}

/*
akshay~$cc 15.c             
akshay~$./a.out 
MallocNanoZone=0
USER=akshay
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
.
.
.
*/