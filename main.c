#include <fcntl.h>   // For open()
#include <stdio.h>    // For printf()
#include <unistd.h>   // For close()
#include "get_next_line.h"  // Include your header

int main(void)
{
    int fd;  // File descriptor
    char *line;

    // Open a file for reading (change "test_file.txt" to your actual file name)
    fd = open("a.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Use get_next_line to read lines from the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);  // Print the line (get_next_line already handles newlines)
        free(line);          // Don't forget to free the allocated memory for each line
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
