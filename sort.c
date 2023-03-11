#include "push_swap.h"

void	three_numbers(t_list **stack)
{
	long long	top;
	long long	mid;
	long long	bot;

	top = *((long long *)(*stack)->content);
	mid = *((long long *)(*stack)->next->content);
	bot = *((long long *)(*stack)->next->next->content);

	if (top > mid && mid > bot) //case 2
	{
		sa_action(stack);
		rra_action(stack);
	}
	else if (top < mid && top < bot) //case 4
	{
		sa_action(stack);
		ra_action(stack);
	}
	else if (top > mid && top > bot) //case 3
		ra_action(stack);
	else if (top > mid && top < bot) // case 1
		sa_action(stack);
	else if (top < mid && top > bot) //case 5
		rra_action(stack);
}

void	five_numbers(t_list **stack)
{
	long long	num;
	int			i;
	t_list		*tmp;
	t_list		*head;
	t_list		*new;

	head = (*stack); // keep head of stack
	tmp = ft_lstnew(NULL); // this will result in having the first node as 0
	while ((*stack)) // copy each node to new stack 'tmp'
	{
		num = *((long long *)(*stack)->content);
		new = ft_lstnew((void *)num);
		ft_lstadd_back(&tmp, new);
		(*stack) = (*stack)->next;
	}
	(*stack) = head; // reset head of stack;
	tmp = tmp->next;
	head = tmp;
	i = 1;
	while (tmp)
	{
		tmp->index = i++;
		printf("tmp:%lld\n", (long long)tmp->content);
		printf("index:%d\n", (int)tmp->index);
		tmp = tmp->next;
	}
	tmp = head;
	// printf("new tmp:%lld\n", (long long)tmp->content);
	// tmp->content = (void *) 22;
	// printf("new tmp:%lld\n", (long long)tmp->content);
	// printf("1111111\n");

	//test
	// while (tmp)
	// {
	// 	printf("new:tmp:%lld\n", (long long)tmp->content);
	// 	tmp = tmp->next;
	// }
	// while ((*stack))
	// {
	// 	printf("stack:%lld\n", *((long long *)(*stack)->content));
	// 	(*stack) = (*stack)->next;
	// }
}