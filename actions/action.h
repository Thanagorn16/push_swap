#ifndef ACTION_H
# define ACTION_H

#include "../push_swap.h"

typedef struct s_list t_list;

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

# endif