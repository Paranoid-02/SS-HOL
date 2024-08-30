/*
============================================================================
Name : 5.c
Author : Akshay Sharma
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 28th Aug, 2024.
============================================================================
*/


#include <sys/types.h> // Import for `creat` system call
#include <sys/stat.h>  // Import for `creat` system call
#include <fcntl.h>     // Import for `creat` system call

void main()
{
    while (1)
    {
        creat("./sample-files/file_1", O_CREAT);
        creat("./sample-files/file_2", O_CREAT);
        creat("./sample-files/file_3", O_CREAT);
        creat("./sample-files/file_4", O_CREAT);
        creat("./sample-files/file_5", O_CREAT);
    }
}