#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	is_err();
void	check_repeated_num();
void	check_asceding_order(long long *arr);
void	check_max_min(long long *arr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sa_action(t_list **stack);
// void	sa_action(t_list *stack);
int		check_digit(char **str);
t_list	*ft_lstnew(void *content);

# endif