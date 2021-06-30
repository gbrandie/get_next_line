#include <stdio.h>
#include "get_next_line.h"

char	*read_file(int fd, char *remainder, char *buf)
{
	int read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		remainder = ft_strjoin(remainder, buf);
		if (find_newline(remainder))
			return (remainder);
	}
	return (remainder);
}

int remainder_checker(char **line, char **remainder, char *p_n)
{
	char *temp;

	if (!p_n)
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	*p_n = '\0';
	p_n++;
	*line = ft_strdup(*remainder);
	if (!p_n)
	{
		free(*remainder);
		*remainder = NULL;
		return (1);
	}
	temp = ft_strdup(p_n);
	free(*remainder);
	*remainder = temp;
	return(1);
}

int get_next_line(int fd, char **line)
{
	static char *remainder;
	char	buf[BUFFER_SIZE + 1];
	char	*p_n;

	*line = ft_strdup("");
	if ((fd < 0)
		|| (line == NULL)
		|| (BUFFER_SIZE <= 0)
		|| (read(fd, buf, 0) < 0)
		|| (!*line))
		return (-1);
	remainder = read_file(fd, remainder, buf);
	if (!remainder)
		return(0);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	p_n = find_newline(remainder);
	return (remainder_checker(line, &remainder,p_n));
}
//int main() {
//	printf("Hello, World!\n");
//	return 0;
//}
