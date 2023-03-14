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

t_list	*sort_copied_stack(t_list **stack)
{
	long long	num;
	long long	tmp_num;
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
	while (tmp) //sort new stack
	{
		if ((long long)tmp->content > (long long)tmp->next->content)
		{
			tmp_num = (long long)tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = (void *) tmp_num;
		}
		tmp = tmp->next;
		if (tmp->next == NULL)
			break;
	}
	tmp = head;
	return (tmp);
}

void	five_numbers(t_list **stack)
{
	int			i;
	t_list		*tmp;
	t_list		*head;

	i = 1;
	tmp = sort_copied_stack(stack);
	head = (*stack);
	while (tmp) // set index to original stack
	{
		while ((*stack))
		{
			if (*((long long *)(*stack)->content) == (long long)tmp->content)
			{
				(*stack)->index = i++;
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		tmp = tmp->next;
	}

	//test
	// while (tmp)
	// {
	// 	printf("new:tmp:%lld\n", (long long)tmp->content);
	// 	tmp = tmp->next;
	// }
	// while ((*stack))
	// {
	// 	printf("stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
	// 	(*stack) = (*stack)->next;
	// }
}