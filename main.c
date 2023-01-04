#include "gnl.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line1;
	char	*line2;
	int		fd1;
	int 	fd2;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2	= open(argv[2], O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 != NULL)
	{
		printf("line1: %s", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
	printf("\n\n");
	while (line2 != NULL)
	{
		printf("line2: %s", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	return (0);
}
