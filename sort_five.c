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

t_list	*push_to_b(int top, int bot, t_list **stack, t_list *head, t_list **stack_b)
{
	t_list	*top_stack;
	t_list	*bot_stack;

	top_stack = NULL;
	bot_stack = NULL;
	if (bot < top) // also in the case of equal distance
	{
		if (ft_lstsize((*stack_b)) == 1) //reset stack to be used for the first action
			(*stack) = head;
		while (bot > 0)
		{
			rra_action(stack);
			bot--;
		}
		bot_stack = ft_lstlast((*stack)); // keep track after the actions
		pb_action(stack, stack_b);
		return (bot_stack);
	}
	else if (top < bot || bot == top)
	{
		if (ft_lstsize((*stack_b)) == 1) //reset stack to be used for the first action
			(*stack) = head;
		while (top > 1 && bot != 1 && top != 1)
		{
			ra_action(stack);
			top--;
		}
		pb_action(stack, stack_b);
		top_stack = (*stack);
		return (top_stack);
	}
	return (bot_stack);
}

void	sort_five(t_list **stack, t_list *head)
{
	int	top;
	int	bot;
	int	i;
	t_list	*stack_b;
	t_list	*lst_node;
	t_list	*top_stack;
	t_list	*bot_stack;

	top_stack = NULL;
	bot_stack = NULL;
	// check index
	stack_b = ft_lstnew(NULL);
	lst_node = ft_lstlast((*stack));
	i = 0;
	while (i < 2)
	{
		top = 0;
		bot = 0;
		if (top_stack) // continue stack from the tracker
			(*stack) = top_stack;
		top = search_top(stack);
		if (bot_stack) // continue stack from the tracker
			(*stack) = top_stack; //* to keep track of the stack if it went to the top < bot first
		else
			(*stack) = lst_node;
		bot = search_bot(ft_lstlast((*stack))); //? better than the above?
		if (bot < top || bot == top) // pushing to stack b
		{
			bot_stack = push_to_b(top, bot, stack, head, &stack_b); //keep track after pushing
			top_stack = ft_lstfront(bot_stack);
		}
		else if (top < bot)
		{
			(*stack) = top_stack; // need this is since we have to keep track of the stack if it get into bot < top first
			top_stack = push_to_b(top, bot, stack, head, &stack_b);
			bot_stack = ft_lstlast(top_stack); //! this will move stack to the last node which won't work properly when pushing.
			// ! do we need the above line if we only need to check the top_stack then assign stack = top_stack?
		}
		i++;
	}
	three_numbers(stack);
	two_number(&stack_b);
	pa_action(stack, &stack_b);
	pa_action(stack, &stack_b);
}

void	five_numbers(t_list **stack)
{
	int			i;
	t_list		*tmp;
	t_list		*head_tmp;
	t_list		*head;

	i = 1;
	tmp = sort_copied_stack(stack);
	head = (*stack);
	head_tmp = tmp;
	while (tmp) // set index to original stack
	{
		while ((*stack))
		{
			if (*((long long *)(*stack)->content) == (long long)tmp->content)
				(*stack)->index = i++;
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		tmp = tmp->next;
	}
	tmp = head_tmp;
	sort_five(stack, head);
}