//Akshay Sharma
//MT2024016
/* 
3. Write a program to create a file and print the file descriptor value. Use `creat()` system call
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
