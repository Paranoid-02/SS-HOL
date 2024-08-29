/* Question : 8. Write a program to execute an executable program.
    1. Use some executable program
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`) */

#include <unistd.h> // Import for `execl` library function

int main()
{
    char *executable_path = "./16b.c";
    char *arg = "file.txt";

    execl(executable_path, executable_path, arg, NULL);
}