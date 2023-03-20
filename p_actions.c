#include "push_swap.h"

void	pa_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL; // set prev for the stack
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "pa\n", 3);
}

void	pb_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp;
	t_list	*lst_node;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL; // set prev for the stack
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);


	// tmp_a = (*stack_a); // keep first node
	// (*stack_a) = (*stack_a)->next; //mode head of stack a
	// // tmp_b = (*stack_b)->next; // keep NULL
	// tmp_a->next = (*stack_b);
	// (*stack_b) = tmp_a;

	// while ((*stack_b))
	// {
	// 	printf("hey\n");
	// 	printf("this is b:%lld\n", *((long long *)(*stack_b)->content));
	// 	// printf("aaaa\n");
	// 	// printf("this is b:%lld\n", (long long)tmp_b->content);
	// 	// printf("this is b:%lld\n", (long long)(*stack_b)->content);
	// 	(*stack_b) = (*stack_b)->next;
	// }
	// // (*stack_b) = NULL;
	// printf("aaaa\n");
	// exit(1);
}