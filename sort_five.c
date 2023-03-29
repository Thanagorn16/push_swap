#include "push_swap.h"

t_list	*push_to_top_b(int top, int bot, t_list **stack, t_swp *pw)
{
	t_list	*top_stack;

	top_stack = NULL;
	if (ft_lstsize(pw->stack_b) == 1) //reset stack to be used for the first action
		(*stack) = pw->head;
	while (top > 1 && bot != 1 && top != 1)
	{
		ra_action(stack);
		top--;
	}
	pb_action(stack, &pw->stack_b);
	top_stack = (*stack);
	return (top_stack);
}

t_list	*push_to_b(int top, int bot, t_list **stack, t_swp *pw)
{
	t_list	*top_stack;
	t_list	*bot_stack;

	top_stack = NULL;
	bot_stack = NULL;
	if (bot < top)
	{
		if (ft_lstsize(pw->stack_b) == 1) //reset stack to be used for the first action
			(*stack) = pw->head;
		while (bot > 0)
		{
			rra_action(stack);
			bot--;
		}
		bot_stack = ft_lstlast((*stack)); // keep track after the actions
		pb_action(stack, &pw->stack_b);
		return (bot_stack);
	}
	else if (top < bot || bot == top)
		top_stack = push_to_top_b(top, bot, stack, pw);
	return (top_stack);
}

void	sort_five(t_list **stack, t_swp *pw)
{
	int	top;
	int	bot;
	int	i;
	t_list	*lst_node;
	t_list	*top_stack;
	t_list	*bot_stack;

	top_stack = NULL;
	bot_stack = NULL;
	lst_node = ft_lstlast((*stack));
	i = 0;
	while (i < 2)
	{
		top = 0;
		bot = 0;
		top = search_top(stack);
		if (bot_stack) // continue stack from the tracker
			(*stack) = top_stack; //* to keep track of the stack if it went to the top < bot first
		else
			(*stack) = lst_node;
		bot = search_bot(ft_lstlast((*stack))); //? better than the above?
		if (bot < top || bot == top) // pushing to stack b
		{
			bot_stack = push_to_b(top, bot, stack, pw); //keep track after pushing
			top_stack = ft_lstfront(bot_stack);
		}
		else if (top < bot)
		{
			(*stack) = top_stack; // need this is since we have to keep track of the stack if it get into bot < top first
			top_stack = push_to_b(top, bot, stack, pw);
			bot_stack = ft_lstlast(top_stack);
		}
		i++;
	}
	three_numbers(stack);
	two_number(&pw->stack_b);
	pa_action(stack, &pw->stack_b);
	pa_action(stack, &pw->stack_b);
}

void	five_numbers(t_list **stack)
{
	int			i;
	t_list		*tmp;
	t_swp		pw;

	i = 1;
	tmp = sort_copied_stack(stack);
	pw.head = (*stack);
	while (tmp) // set index to original stack
	{
		while ((*stack))
		{
			if (*((long long *)(*stack)->content) == (long long)tmp->content)
				(*stack)->index = i++;
			(*stack) = (*stack)->next;
		}
		(*stack) = pw.head;
		tmp = tmp->next;
	}
	pw.stack_b = ft_lstnew(NULL);
	sort_five(stack, &pw);
}