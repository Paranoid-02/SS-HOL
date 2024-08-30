//Akshay Sharma
//MT2024016
/* Question : Write a program to print the following information about a given file - 
    1. Inode 
    2. Number of hard links 
    3. UID 
    4. GID 
    5. Size 
    6. Block size 
    7. Number of blocks 
    8. Time of last access 
    9. Time of last modification 
    10. Time of last change
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
    char filename[256];
    struct stat file_stat;

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", filename);
    printf("Inode: %ld\n", file_stat.st_ino);
    printf("Number of hard links: %ld\n", file_stat.st_nlink);
    printf("UID: %d\n", file_stat.st_uid);
    printf("GID: %d\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Block size: %ld bytes\n", file_stat.st_blksize);
    printf("Number of blocks: %ld\n", file_stat.st_blocks);
    printf("Time of last access: %s", ctime(&file_stat.st_atime));
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last change: %s", ctime(&file_stat.st_ctime));

    return 0;
}