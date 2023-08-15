/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:19:00 by ccarrace          #+#    #+#             */
/*   Updated: 2023/08/15 21:20:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		line = "";
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
		}
		fd = close(fd);
		return (0);
	}
}
