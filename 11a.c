#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *file;
    int fd;
    int dupfd;

    file = argv[1];
    fd = open(file, O_WRONLY | O_APPEND);
    if (fd == -1)
    {
        perror("Didn't write");
    }

    dupfd = dup(fd);

    // using original
    if (write(fd, "Hello, ", 7) != 7)
    {
        perror("write");
    }

    // using duplicate
    if (write(dupfd, "World!", 6) != 6)
    {
        perror("write");
    }

    close(fd);
    close(dupfd);
}