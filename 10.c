/*10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use `lseek`) and write again 10 bytes.
    1. Check the return value of `lseek`
    2. Open the file with `od` and check the empty spaces in between the data.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char *file;
    int fd;
    int offset;
    int byteswritten;

    file = argv[1];
    fd = open(file, O_RDWR);

    if (fd == -1)
    {
        perror("invalid file");
    }

    offset = lseek(fd, 10, SEEK_SET);
    byteswritten = write(fd, "ABCEDEFGHIJ", 10);
    if (byteswritten == -1)
    {
        perror("Error while writing to the file!");
        _exit(1);
    }

    offset = lseek(fd, 10, SEEK_CUR);
    byteswritten = write(fd, "1234567890", 10);
    if (byteswritten == -1)
    {
        perror("Error while writing to the file!");
        _exit(1);
    }

    printf("return value of lseek: %d\n", offset);
    close(fd);
}