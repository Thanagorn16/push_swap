#include "push_swap.h"

void	pa_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "pa\n", 3);
}

void	pb_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);
}