#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "actions/action.h"

typedef struct s_list
{
	void			*content;
	int				index;
	int				i;
	int				j;
	int				k;
	int				size;
	long long		*arr; // keep the value in heap (remain in the memory)
	char			**set;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	printr(t_list **stack);
void	printc(t_list **stack);
void	printl(t_list **stack);
void	is_err();
void	check_repeated_num(long long *arr, int size);
void	check_asceding_order(long long *arr, int size);
void	check_max_min(long long *arr, int size);
void	double_free_int(long long *arr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	two_number(t_list **stack);
void	three_numbers(t_list **stack);
void	five_numbers(t_list **stack);
void	sort_big_stack();
void	sort_stack(t_list **stack, int size);
void	sort_tmp(t_list *tmp);
int		check_digit(char **str);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfront(t_list *lst);
t_list	*sort_copied_stack(t_list **stack);

# endif