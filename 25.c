/*
============================================================================
Name : 25.c
Author : Akshay Sharma
Description : Write a program to create three child processes. The parent should wait for a particular child (use `waitpid` system call).
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3;
    int status;

    // first child
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid1 == 0)
    {
        // first child process
        printf("first child pid:%d\n", getpid());
        sleep(5);
        return 1;
    }

    // second child
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid2 == 0)
    {
        // second child process
        printf("second child pid:%d\n", getpid());
        sleep(10);
        return 2;
    }

    // third child
    pid3 = fork();
    if (pid3 == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid3 == 0)
    {
        // third child process
        printf("third child pid:%d\n", getpid());
        sleep(15);
        return 3;
    }

    // Parent process
    printf("Parent process (PID:%d)\n", getpid());

    // wait for the second child process
    pid_t wpid = waitpid(pid2, &status, 0);
    if (wpid == -1)
    {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status))
    {
        printf("Second child process (PID: %d) exited with status %d\n", wpid, WEXITSTATUS(status));
    }
    else
    {
        printf("Second child process (PID: %d) terminated abnormally\n", wpid);
    }

    return 0;
}

/*
first child pid:37950
second child pid:37951
Parent process (PID:37949)
third child pid:37952
Second child process (PID: 37951) exited with status 2
*/