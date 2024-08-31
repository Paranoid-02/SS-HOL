/*
============================================================================
Name : 5.c
Author : Akshay Sharma
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 28th Aug, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>     

int main()
{
    while (1)
    {
        creat("./file_1", O_CREAT);
        creat("./file_2", O_CREAT);
        creat("./file_3", O_CREAT);
        creat("./file_4", O_CREAT);
        creat("./file_5", O_CREAT);
    }
}