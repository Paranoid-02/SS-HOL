/* Question : Write a program to find the type of a file.
    1. Input should be taken from command line.
    2. Program should be able to identify any type of a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    struct stat file_stat;
    int fd;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    close(fd);

    printf("File type: ");

    if (S_ISREG(file_stat.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(file_stat.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(file_stat.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(file_stat.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(file_stat.st_mode))
        printf("FIFO/pipe\n");
    else if (S_ISLNK(file_stat.st_mode))
        printf("Symbolic link\n");
    else if (S_ISSOCK(file_stat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}