#include "push_swap.h"

void	keep_sorting(t_list *tmp, t_list *head)
{
	while (tmp)
	{
		if ((long long)tmp->content > (long long)tmp->next->content)
		{
			tmp = head;
			sort_tmp(tmp);
		}
		tmp = tmp->next;
		if (tmp->next == NULL)
			break ; //break the sub loop
	}
}

void	sort_tmp(t_list *tmp)
{
	long long	tmp_num;
	t_list		*head;

	head = tmp;
	while (tmp) //sort new stack
	{
		if ((long long)tmp->content > (long long)tmp->next->content) // first time sorting the stack until reaching NULL
		{
			tmp_num = (long long)tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = (void *) tmp_num;
		}
		tmp = tmp->next;
		if (tmp->next == NULL) // end the first sorting, then repeatly sort until the least num get to the top of the stack
		{
			tmp = head;
			keep_sorting(tmp, head);
			break; //break the main loop
		}
	}
}

t_list	*sort_copied_stack(t_list **stack)
{
	long long	num;
	t_list		*tmp;
	t_list		*head;
	t_list		*new;

	head = (*stack); // keep head of stack
	tmp = NULL;
	while ((*stack)) // copy each node to new stack 'tmp'
	{
		num = *((long long *)(*stack)->content);
		new = ft_lstnew((void *)num);
		ft_lstadd_back(&tmp, new);
		(*stack) = (*stack)->next;
	}
	(*stack) = head; // reset head of stack;
	head = tmp;
	sort_tmp(tmp);
	tmp = head;
	return (tmp);
}

int	search_top(t_list **stack)
{
	int	top;

	top = 0;
	while ((*stack)) // traverse from top
	{
		if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
		{
			top++;
			break ;
		}
		top++;
		(*stack) = (*stack)->next;
	}
	return (top);
}

int	search_bot(t_list *stack)
{
	int	bot;

	bot = 0;
	while (stack) // traverse from bot
	{
		if (stack->index == 1 || stack->index == 2) //get index1 position
		{
			bot++;
			break ;
		}
		bot++;
		stack = stack->prev;
	}
	return (bot);
}