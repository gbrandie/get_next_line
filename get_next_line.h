#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*find_newline(char *str);
int		remainder_checker(char **line, char **remainder, char*p_n);
char	*ft_strjoin(char *remainder, char *buffer);
int		get_next_line(int fd, char **line);
#endif
