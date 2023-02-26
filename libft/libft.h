#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_split
{
	int		count;
	int		slot;
	size_t	i;
}	t_split;

size_t	ft_strlen(const char *str);
int ft_atoi(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
void	double_free(char **arr);
char	**ft_split(char const *s, char c);

#endif