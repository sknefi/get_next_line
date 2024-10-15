#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	// Open the file "test.txt" for reading
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	// Read and print each line using get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("------------\n");

	fd = open("test.txt", O_RDONLY);
	(line = get_next_line(fd));
	printf("%s", line);
	free(line);	(line = get_next_line(fd)) ;
	printf("%s", line);
	free(line);	(line = get_next_line(fd));
	printf("%s", line);
	free(line);	


	close(fd);
	return (0);
}
