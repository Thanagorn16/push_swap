#include "push_swap.h"

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