/*
============================================================================
Name : 3.c
Author : Akshay Sharma
Description : Write a program to create a file and print the file descriptor value. Use `creat()` system call
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = creat("my_file.txt", 0644); // Create file with read/write permissions

    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    return 0;
}
