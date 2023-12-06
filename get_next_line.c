/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:05:42 by ccarrace          #+#    #+#             */
/*   Updated: 2023/12/06 13:15:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line_and_remainder(char **static_var)
{
	char	*line;
	char	*remainder;
	int		i;

	i = 0;
	while ((*static_var)[i] != '\n' && (*static_var)[i] != '\0')
		i++;
	if ((*static_var)[i] == '\n' && (*static_var)[i] != '\0')
		i++;
	line = ft_substr(*static_var, 0, i);
	if (!line || *line == '\0')
		return (ft_free(&line));
	remainder = ft_substr(*static_var, i, ft_strlen(*static_var) - i);
	free(*static_var);
	*static_var = remainder;
	return (line);
}

char	*dump_data_into_static_var(int fd, char *static_var)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&static_var));
	*buffer = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free(&static_var));
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(static_var, buffer);
		static_var = temp;
	}
	if (buffer)
		free(buffer);
	return (static_var);
}

char	*get_next_line(int fd)
{
	static char	*static_var;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_var = dump_data_into_static_var(fd, static_var);
	if (!static_var || *static_var == '\0')
		return (ft_free(&static_var));
	line = extract_line_and_remainder(&static_var);
	if (!line)
		return (ft_free(&static_var));
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Wrong args!\n");
		return (1);
	}
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
}*/
