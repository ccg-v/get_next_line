#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		write (1, "No file specified!\n", 19);
	else if (argc > 2)
		write (1, "Too many arguments!\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
/*		if (fd == -1)
		{
			write (1, "File not found!\n", 16);
			return (-1);
		}
*/
		line = "";
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("%s", line);	
		}
		fd = close(fd);
		return (0);
	}
}
