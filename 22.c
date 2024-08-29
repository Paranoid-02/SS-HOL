// Q.Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    pid_t pid;
    char message[] = "Hello World!\n";

    fd = open("file.txt", O_WRONLY | O_CREAT);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child Process
        write(fd, message, strlen(message));
        printf("Child process wrote to the file\n");
    }
    else
    {
        // Parent Process
        write(fd, message, strlen(message));
        printf("Parent process wrote to the file\n");
    }

    close(fd);

    return 0;
}

/*
output
akshay~$./a.out
    Parent process wrote to the file
    Child process wrote to the file
akshay~$cat file.txt
    Hello World!
    Hello World!
*/