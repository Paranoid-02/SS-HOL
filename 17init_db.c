/* Name : Akshay Sharma
 * Question : Write a program to open a file, store a ticket number, and exit.
 */

#include <unistd.h>    // For `close`
#include <fcntl.h>     // For `open`, `O_CREAT`, `O_RDWR`
#include <sys/types.h> // For `open`
#include <sys/stat.h>  // For `open`
#include <stdio.h>     // For `printf`

int main() {
    int fd;
    struct {
        int ticket_no;
    } db;

    db.ticket_no = 10;

    // Open the file "db" in read/write mode, create it if it doesn't exist, with permissions 0744
    fd = open("db", O_CREAT | O_RDWR, 0744);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write the initial ticket number to the file
    write(fd, &db, sizeof(db));
    close(fd); // Close the file after writing

    // Open the file again in read-only mode to verify the content
    fd = open("db", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the ticket number from the file
    read(fd, &db, sizeof(db));
    printf("Ticket no: %d\n", db.ticket_no); // Should print "Ticket no: 10"
    close(fd); // Close the file after reading

    return 0;
}

/*
    @akshay~$
    Ticket no: 10
*/
