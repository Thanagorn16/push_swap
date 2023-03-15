#include "push_swap.h"

void	ra_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack)
		return ;
	lst_node = ft_lstlast((*stack)); // get last node
	tmp = (*stack); //copy head (3)
	(*stack) = (*stack)->next; //stack = second node (-2)
	lst_node->next = tmp; //

	// printf("stack_ra:%lld\n", *((long long *)(*stack)->content));
	// printf("stack_ra:%lld\n", *((long long *)(*stack)->next));
	// printf("tmp:%lld\n", *((long long *)tmp->next));
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack)
		return ;
	lst_node = ft_lstlast((*stack)); // get last node
	tmp = (*stack); //copy head (3)
	(*stack) = (*stack)->next; //stack = second node (-2)
	lst_node->next = tmp; //
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack_a || !stack_b)
		return ;
	// stack a
	lst_node = ft_lstlast((*stack_a)); 
	tmp = (*stack_a); 
	(*stack_a) = (*stack_a)->next; 
	lst_node->next = tmp; 
	tmp->next = NULL;
	// stack b
	lst_node = ft_lstlast((*stack_b)); 
	tmp = (*stack_b); 
	(*stack_b) = (*stack_b)->next; 
	lst_node->next = tmp; 
	tmp->next = NULL;
	write(1, "rr\n", 3);
}