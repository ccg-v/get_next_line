/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:34:18 by ccarrace          #+#    #+#             */
/*   Updated: 2023/12/06 13:31:04 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char));
		if (!str1)
			return (NULL);
		*str1 = '\0';
	}
	new_str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!new_str)
		return (ft_free(&str1));
	i = -1;
	while (str1[++i] != '\0')
		new_str[i] = str1[i];
	j = -1;
	while (str2[++j] != '\0')
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
	{
		new_str = (char *)malloc(sizeof(char));
		if (!new_str)
			return (NULL);
		*new_str = '\0';
		return (new_str);
	}
	if ((start + len) > ft_strlen(str))
		len = ft_strlen(str) - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}
