//Akshay Sharma
//MT2024016
/*
Question: Write a program to perform mandatory locking. 
    - Implement write lock 
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    char *file;
    struct flock lock, lockStatus;
    int fd;

    if(argc != 2){
        printf("Pass the file name to be locked as the argument!");
    }
    else{
        file = argv[1];

        //Defining lock parameters
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

        lockStatus = lock;
        fd = open(file,O_RDWR);

        fcntl(fd,F_GETLK,&lockStatus);

        if(lockStatus.l_type == F_WRLCK){
            printf("File already locked for writing\n");
        }
        else if(lockStatus.l_type == F_RDLCK){
            printf("File already locked for reading\n");
        }
        else{
            //Applying Lock
            fcntl(fd,F_SETLK,&lock);
            printf("File is now locked for writing\n");
        }
    }
}