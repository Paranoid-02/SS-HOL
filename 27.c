/*
============================================================================
Name : 27.c
Author : Akshay Sharma
Description:  Write a program to execute `ls -Rl` by the following system calls 
    1. `execl` 
    2. `execlp` 
    3. `execle` 
    4. `execv` 
    5. `execvp`
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    char *env[] = {NULL};

    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    printf("execl failed\n");

    printf("\nUsing execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);
    printf("execlp failed\n");

    printf("\nUsing execle:\n");
    execle("/bin/ls", "ls", "-Rl", NULL, env);
    printf("execle failed\n");

    printf("\nUsing execv:\n");
    execv("/bin/ls", args);
    printf("execv failed\n");

    printf("\nUsing execvp:\n");
    execvp("ls", args);
    printf("execvp failed\n");

    return 0;
}