//Akshay Sharma
//MT20240161
// Write a program to get maximum and minimum real time priority.

#include <stdio.h>
#include <sched.h>

int main()
{
    int maxrtpr, minrtpr;

    maxrtpr = sched_get_priority_max(SCHED_RR);
    if (maxrtpr == -1)
    {
        perror("sched_get_priority_max");
        return 1;
    }

    minrtpr = sched_get_priority_min(SCHED_RR);
    if (minrtpr == -1)
    {
        perror("sched_min_priority_min");
        return 1;
    }

    printf("Max real time priority: %d\n", maxrtpr);
    printf("Min real time priority: %d\n", minrtpr);

    return 0;
}

/*
output
akshay~$cc 28.c
akshay~$./a.out
    Max real time priority: 47
    Min real time priority: 15
*/