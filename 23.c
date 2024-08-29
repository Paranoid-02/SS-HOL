// Q.Write a program to create a Zombie state of the running program.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        // Child Process
        printf("Child process (PID:%d)\n", getpid());
        return 0;
    }
    else
    {
        // Parent Process
        printf("Parent process (PID:%d)\n", getpid());
        while (1)
        {
            sleep(1);
        }
    }

    return 0;
}


/*
OUTPUT
Parent process (PID:2295)
Child process (PID:2296)

akshay~$ps aux | grep 'Z'
USER               PID  %CPU %MEM      VSZ    RSS   TT  
akshay            2296   0.0  0.0        0      0 s002  Z+    3:36PM   0:00.00 <defunct>
*/
