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