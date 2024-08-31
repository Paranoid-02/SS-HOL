/*
============================================================================
Name : 6.c
Author : Akshay Sharma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2024.
============================================================================
*/


#include <unistd.h> // Import for `read` & `write` system call
#include <stdio.h>  // Import for `perror` function

int main()
{
    char *buffer[100];
    int readByteCount, writeByteCount;
    while (1)
    {
        readByteCount = read(STDIN_FILENO, buffer, 1);
        writeByteCount = write(STDOUT_FILENO, buffer, 1);

        if (readByteCount == -1 || writeByteCount == -1)
        {
            perror("Error while reading from STDIN / writing to STDOUT");
            break;
        }
    }
}

/*
akshay~$./a.out            
Wassup?
Wassup?
I am good
I am good
*/