/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:45:02 by ccarrace          #+#    #+#             */
/*   Updated: 2022/10/14 16:44:29 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_extract_remainder(char *depot)
{
	int		i;
	char	*remainder;

	i = 0;
	while (depot[i] != '\n' && depot[i] != '\0')
		i++;
	if (depot[i] != '\0' && depot[i] == '\n')
		i++;
	remainder = ft_substr(depot, i, ft_strlen(depot) - i);
	if (!remainder || *remainder == '\0')
	{
		free (remainder);
		remainder = NULL;
	}
	return (remainder);
}

static char	*ft_extract_line(char *depot)
{
	int		i;
	char	*line;

	i = 0;
	while (depot[i] != '\n' && depot[i] != '\0')
		i++;
	if (depot[i] != '\0' && depot[i] == '\n')
		i++;
	line = ft_substr(depot, 0, i);
	if (!line || *line == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static char	*ft_load_data(int fd, char *buffer, char *depot)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (0);
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!depot)
			depot = ft_strdup("");
		temp = ft_strdup(depot);
		free(depot);
		depot = NULL;
		depot = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (depot);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char static	*depot[OPEN_MAX];
	char		*store;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	store = ft_load_data(fd, buffer, depot[fd]);
	free(buffer);
	buffer = NULL;
	if (!store || *store == '\0')
	{
		free (depot[fd]);
		depot[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(store);
	depot[fd] = ft_extract_remainder(store);
	free (store);
	store = NULL;
	return (line);
}
