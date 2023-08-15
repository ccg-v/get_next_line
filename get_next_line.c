/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:05:42 by ccarrace          #+#    #+#             */
/*   Updated: 2023/08/16 00:05:17 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

static void	ft_extract_remainder(char **static_var)
{
	int		i;
	char	*remainder;

	i = 0;
	while ((*static_var)[i] != '\n' && (*static_var)[i] != '\0')
		i++;
	if ((*static_var)[i] != '\0' && (*static_var)[i] == '\n')
		i++;
	remainder = ft_substr(*static_var, i, ft_strlen(*static_var) - i);
	free(*static_var);
	*static_var = ft_strdup(remainder);
	free (remainder);
	remainder = NULL;
	if (!*static_var || **static_var == '\0')
		ft_free(static_var);
}

static char	*ft_extract_line(char **static_var)
{
	int		i;
	char	*line;

	i = 0;
	while ((*static_var)[i] != '\n' && (*static_var)[i] != '\0')
		i++;
	if ((*static_var)[i] != '\0' && (*static_var)[i] == '\n')
		i++;
	line = ft_substr(*static_var, 0, i);
	if (!line || *line == '\0')
		ft_free(&line);
	return (line);
}

static int	dump_data_into_static_var(int fd, char *buffer, char **static_var)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_free(static_var); 
			return (0);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!(*static_var))
			*static_var = ft_strdup("");
		temp = ft_strdup(*static_var);
		free(*static_var);
		*static_var = ft_strjoin(temp, buffer);
		ft_free(&temp);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char static	*static_var;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	dump_data_into_static_var(fd, buffer, &static_var);
	ft_free(&buffer);
	line = NULL;
	if (!static_var || (static_var && *static_var == '\0'))
	{
		ft_free(&static_var);
		return (NULL);
	}
	line = ft_extract_line(&static_var);
	ft_extract_remainder(&static_var);
	return (line);
}
