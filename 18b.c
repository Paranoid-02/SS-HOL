/*
============================================================================
Name : 18b.c
Author : Akshay Sharma
Description : Write a program to perform Record locking.
                       a. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    struct
    {
        int trainno;
        int tickno;
    } db;
    int fd = open("record.txt", O_RDWR);
    struct flock lock;
    int train;
    printf("Enter the train no (1,2,3,4)");
    scanf("%d", &train);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (train - 1) * sizeof(db);
    lock.l_pid = getpid();
    lock.l_len = sizeof(db);
    lseek(fd, (train - 1) * sizeof(db), SEEK_SET);
    printf("PLease wait \n");
    fcntl(fd, F_SETLKW, &lock);
    read(fd, &db, sizeof(db));
    printf("no of tickets sold is %d\n", db.tickno);
    lock.l_type = F_UNLCK;
    printf("press Enter to exit\n");
    getchar();
    getchar();
    fcntl(fd, F_SETLKW, &lock);

    return 0;
}

/*
akshay~$ cc 18b.c
akshay~$ ./a.out
Enter the train no (1,2,3,4)3
PLease wait
no of tickets sold is 19
press Enter to exit

*/