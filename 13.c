/*
============================================================================
Name : 13.c
Author : Akshay Sharma
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

#define TIMEOUT 10

int main()
{
    fd_set readFDSet, writeFDSet;
    struct timeval tv;
    int returnVal;

    FD_SET(STDIN_FILENO, &readFDSet);
    FD_SET(STDOUT_FILENO, &writeFDSet);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    printf("Waiting for input for %d seconds...\n", TIMEOUT);

    returnVal = select(1, &readFDSet, &writeFDSet, NULL, &tv);

    if (returnVal == -1)
        perror("ERROR ");
    else if (returnVal) // read from STDIN
        printf("Data is available now");
    else // select timed out
        printf("No data was given in 10 seconds");
}

/*
akshay~$cc 13.c             
akshay~$./a.out             
Waiting for input for 10 seconds...
Hello
Data is available now
*/