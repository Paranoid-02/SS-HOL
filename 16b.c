/*
Question: Write a program to perform mandatory locking. 
    - Implement read lock 
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
    char *file;
    struct flock lock,lockStatus;
    int fd;

    if(argc != 2){
        printf("pass the file to be locked as the argument");
    }else{  
        file = argv[1];

        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

        lockStatus = lock;

        fd = open(file,O_RDONLY);

        fcntl(fd,F_GETLK,&lockStatus);

        if(lockStatus.l_type == F_WRLCK)
            print("File already locked for writing\n");
        else if(lockStatus.l_type == F_RDLCK)
            printf("File already locked for reading\n");
        else{
            //Applying lock
            fcntl(fd,F_SETLK,&lock);
            printf("File is now locked for reading\n");
        }
    }
}   