#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof (char));
	if (!s1 || !s2 || !newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

char	*ft_funct(char *str, char **stat_str)
{
	char	*new_str;
	char	*temp;

	new_str = ft_strjoin(str, " i adeu");
	temp = ft_strjoin(*stat_str, " y adios");
	*stat_str = temp;
	return (new_str);
}

int	main(void)
{
	char		*str;
	static char	*stat_str;

	str = "Hola";
	stat_str = "Hola";
	str = ft_funct(str, &stat_str);
	printf("str = %s\n", str);
	printf("stat_str = %s\n", stat_str);
	free(str);
	free(stat_str);
	return (0);
}
