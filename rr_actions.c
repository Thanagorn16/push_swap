#include "push_swap.h"

void	rra_action(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	while (tmp->next != (*stack))
		tmp = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb_action(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	while (tmp->next != (*stack))
		tmp = tmp->next;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	// stack a
	tmp = (*stack_a);
	(*stack_a) = ft_lstlast((*stack_a));
	(*stack_a)->next = tmp;
	while (tmp->next != (*stack_a))
		tmp = tmp->next;
	tmp->next = NULL;

	// stack b
	tmp = (*stack_b);
	(*stack_b) = ft_lstlast((*stack_b));
	(*stack_b)->next = tmp;
	while (tmp->next != (*stack_b))
		tmp = tmp->next;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}