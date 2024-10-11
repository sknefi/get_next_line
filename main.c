#include <fcntl.h>  // For open
#include <unistd.h> // For close
#include <stdio.h>  // For printf
#include <stdlib.h>
#include "get_next_line.h" // Your get_next_line function

int main(void)
{
    int fd;
    char *line;

    // Open a file to test (change "test_file.txt" to a valid file path)
    fd = open("a.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: could not open file\n");
        return (1);
    }

    // Repeatedly call get_next_line to read lines from the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line
        free(line);         // Free the line after printing
    }

    // Close the file descriptor
    close(fd);

    return (0);
}
