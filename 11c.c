/*
============================================================================
Name : 11c.c
Author : Akshay Sharma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not using `dup`
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Pass filename as parameter");
    }
    else
    {
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND);
        if (fd == -1)
        {
            printf("Problem while opening the file");
            return 0;
        }
        int dupfd = fcntl(fd, F_DUPFD);
        if (dupfd == -1)
        {
            printf("Problem while duplicating the file");
            return 0;
        }
        int writecount = write(dupfd, "Using duplicate File descriptor", 31);
        if (writecount == -1)
        {
            printf("Problem while writing the file");
        }

        return 0;
    }
}

/*
akshay~$ cat file11c.txt
Using duplicate File descriptor
*/