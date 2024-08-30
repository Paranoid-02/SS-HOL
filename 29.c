//Akshay Sharma
//MT20240161
/*
Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int curr_policy, new_policy, max_prio, ch;
    struct sched_param param;

    curr_policy = sched_getscheduler(0); // current process
    if (curr_policy == -1)
    {
        perror("sched");
        return 1;
    }

    printf("current scheduling policy :  ");
    switch (curr_policy)
    {
    case SCHED_OTHER:
        printf("SCHED_OTHER (Normal)\n");
        break;
    case SCHED_FIFO:
        printf("SCHED_FIFO (First-In,First-Out)\n");
        break;
    case SCHED_RR:
        printf("SCHED_RR (Round Robin)\n");
        break;
    default:
        printf("unknown policy\n");
    }

    printf("Enter 1 for FIFO or 2 for RR");
    scanf("%d", &ch);

    if (ch == 1)
        new_policy = SCHED_FIFO;
    else if (ch == 2)
        new_policy = SCHED_RR;
    else
    {
        printf("Invalid Choice\n");
        return 1;
    }

    max_prio = sched_get_priority_max(new_policy);
    if (max_prio == -1)
    {
        perror("sched_get_priority_max");
        return 1;
    }

    // Set new policy

    param.sched_priority = max_prio;
    ch = sched_setscheduler(0, new_policy, &param);
    if (ch == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to: ");
    switch (new_policy)
    {
    case SCHED_FIFO:
        printf("SCHED_FIFO (First-In,First-Out)\n");
        break;
    case SCHED_RR:
        printf("SCHED_RR (Round Robin)\n");
        break;
    }
    return 0;
}

/*
[parallels@fedora-linux-38 Downloads]$ cc 29.c
[parallels@fedora-linux-38 Downloads]$ sudo ./a.out
[sudo] password for parallels:
current scheduling policy :  SCHED_OTHER (Normal)
Enter 1 for FIFO or 2 for RR2
Scheduling policy changed to: SCHED_RR (Round Robin)
*/