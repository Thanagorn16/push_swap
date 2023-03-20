#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	printr(t_list **stack);
void	printc(t_list **stack);
void	printl(t_list **stack);
void	is_err();
void	check_repeated_num(long long *arr);
void	check_asceding_order(long long *arr);
void	check_max_min(long long *arr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sa_action(t_list **stack);
void	sb_action(t_list **stack);
void	ss_action(t_list **stack_a, t_list **stack_b);
void	ra_action(t_list **stack);
void	rb_action(t_list **stack);
void	rr_action(t_list **stack_a, t_list **stack_b);
void	rra_action(t_list **stack);
void	rrb_action(t_list **stack);
void	rrr_action(t_list **stack_a, t_list **stack_b);
void	pa_action(t_list **stack_a, t_list **stack_b);
void	pb_action(t_list **stack_a, t_list **stack_b);
void	three_numbers(t_list **stack);
void	five_numbers(t_list **stack);
int		check_digit(char **str);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfront(t_list *lst);
t_list	*sort_copied_stack(t_list **stack);

# endif