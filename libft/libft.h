#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

typedef struct s_split
{
	int		count;
	int		slot;
	size_t	i;
}	t_split;

void	ft_putstr_fd(char *s, int fd);
void	double_free(char **arr);
// void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
// t_list	*ft_lstnew(void *content);

#endif