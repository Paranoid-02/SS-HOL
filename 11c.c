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
    char *file;
    int fd;
    int dupfd;

    file = argv[1];
    fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Didn't write");
    }

    // Duplicate the file descriptor using dup2
    dupfd = fcntl(fd, F_DUPFD); // Duplicate to file descriptor 10
    if (dupfd == -1)
    {
        perror("dup2");
        close(fd);
    }

    // Write to the file using the original descriptor
    if (write(fd, "Hello, ", 7) != 7)
    {
        perror("write");
    }

    // Write to the file using the duplicated descriptor
    if (write(10, "World!", 6) != 6)
    {
        perror("write");
    }

    close(fd);
    close(10);
}