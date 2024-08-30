//Akshay Sharma
//MT2024016
// Question : Write a program to create an orphan process

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // Bacha Process
        printf("Child process (PID:%d, PPID:%d)\n", getpid(), getppid());
        sleep(10);
        printf("Child Process exiting...\n");
    }
    else
    {
        printf("Parent Process (PID:%d)\n", getpid());
        printf("Child Process (PID:%d)\n", pid);
    }

    return 0;
}

/*
output
Parent Process (PID:6565)
Child Process (PID:6566)
Child process (PID:6566, PPID:6565)
akshay~$Child Process exiting...

akshay~$ps -al
  UID   PID  PPID        F CPU PRI NI       SZ    RSS WCHAN     S             ADDR TTY           TIME CMD
  501  6566     1        6   0  31  0 410077792    864 -      S                   0 ttys002    0:00.00 ./a.out*/