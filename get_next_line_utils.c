#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char *find_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *remainder, char *buf)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!remainder)
		return (ft_strdup(buf));
	result = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(remainder) + 1));
	if (!result)
		return (NULL);
	while (remainder[i])
		result[i++] = remainder[j++];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	free(remainder);
	result[i] = '\0';
	return (result);
}
