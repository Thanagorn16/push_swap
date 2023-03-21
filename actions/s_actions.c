#include "action.h"

void	sa_action(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = (*stack); // keep tmp as the first node (head)
	(*stack) = (*stack)->next; //head to the second node
	tmp->next =(*stack)->next;
	(*stack)->next = tmp;
	write(1, "sa\n", 3);
}

void	sb_action(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = (*stack); // keep tmp as the first node (head)
	(*stack) = (*stack)->next; //head to the second node
	tmp->next =(*stack)->next;
	(*stack)->next = tmp;
	write(1, "sb\n", 3);
}

void	ss_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	// stack_a
	if (!stack_a || !stack_b)
		return ;
	tmp_a = (*stack_a); // keep tmp as the first node (head)
	(*stack_a) = (*stack_a)->next; //head to the second node
	tmp_a->next =(*stack_a)->next;
	(*stack_a)->next = tmp_a;
	// stack_b
	tmp_b = (*stack_b); // keep tmp as the first node (head)
	(*stack_b) = (*stack_b)->next; //head to the second node
	tmp_b->next =(*stack_b)->next;
	(*stack_b)->next = tmp_b;
	write(1, "ss\n", 3);
}
