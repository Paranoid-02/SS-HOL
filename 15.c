//Akshay Sharma
//MT2024016
// Question : Write a program to display the environmental variable of the user (use environ).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    extern char **environ; // Declare the environ array

    for (char **env = environ; *env != NULL; ++env)
    {
        printf("%s\n", *env);
    }

    return 0;
}