#include "push_swap.h"

void	sort_tmp(t_list *tmp)
{
	long long	tmp_num;
	long long	prev_num;
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
			break; //break the main loop
		}
	}
}

t_list	*sort_copied_stack(t_list **stack)
{
	long long	num;
	long long	tmp_num;
	long long	prev_num;
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
		// printf("TOP search\n");
		if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
		{
			top++;
			// printf("top:%d\n", top);
			// printc(stack);
			break ;
		}
		top++;
		(*stack) = (*stack)->next;
	}
	printf("\n");
	return (top);
}

int	search_bot(t_list *stack)
{
	int	bot;

	bot = 0;
	while (stack) // traverse from bot
	{
		// printf("BOT search\n");
		if (stack->index == 1 || stack->index == 2) //get index1 position
		{
			bot++;
			// printf("bot:%d\n", bot);
			// printc(&stack);
			break ;
		}
		bot++;
		stack = stack->prev;
	}
	printf("\n");
	return (bot);
}

t_list	*push_to_b(int top, int bot, t_list **stack, t_list *head, t_list **stack_b)
{
	t_list	*top_stack;
	t_list	*bot_stack;

	if (bot < top || bot == top) // also in the case of equal distance
	{
		// printl(stack);
		// exit(1);
		if (ft_lstsize((*stack_b)) == 1) //reset stack to be used for the first action
		{
			(*stack) = head;
		}
		while (bot > 0)
		{
			rra_action(stack);
			// printr(stack);
			// exit(1);
			bot--;
		}
		bot_stack = ft_lstlast((*stack)); // keep track after the actions
		pb_action(stack, stack_b);
		// printf("in bot < top\n");
		// printr(stack);
		return (bot_stack);
	}
	else if (top < bot)
	{
		// printf("size in if:%d\n", ft_lstsize((*stack_b)));
		// printl(stack);
		// exit(1);
		if (ft_lstsize((*stack_b)) == 1) //reset stack to be used for the first action
			(*stack) = head;
		// printf("size in if:%d\n", ft_lstsize((*stack)));
		while (top > 1)
		{
			ra_action(stack);
			top--;
		}
		pb_action(stack, stack_b);
		top_stack = (*stack);
		// printf("in top < bot\n");
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
	t_list	*top_stack = NULL;
	t_list	*bot_stack = NULL;

	// check index
	stack_b = ft_lstnew(NULL);
	lst_node = ft_lstlast((*stack));
	i = 0;
	while (i < 2)
	{
		// printf("start size:%d\n", ft_lstsize(stack_b));
		top = 0;
		bot = 0;
		// if (top_stack->next) // continue stack from the tracker
		if (top_stack) // continue stack from the tracker
		{
			// printf("in top_stack\n");
			(*stack) = top_stack;
			// printf("get TOP_stack in:%d\n", i);
			// printl(stack);
			// exit(1);
		}
		top = search_top(stack);
		// top_stack = (*stack); // keep track of the stack start from the top
		// top_stack = head; //!this does not keep track if bot < top, it will just start again with original stack
		// if (bot_stack->prev) // continue stack from the tracker
		if (bot_stack) // continue stack from the tracker
		{
			// (*stack) = bot_stack;
			(*stack) = top_stack; //* to keep track of the stack if it went to the top < bot first
			//? if the above line already existed, should the 'bot_stack' in top < bot be needed?
			// printl(stack);
			// exit(1);
			// printf("get BOT_stack in:%d\n", i);
		}
		else
			(*stack) = lst_node;
		// bot = search_bot((*stack));
		bot = search_bot(ft_lstlast((*stack))); //? better than the above?
		// bot_stack = (*stack); // keep track of the stack start from the bottom //! no use of the line
		if (bot < top || bot == top) // pushing to stack b
		{
			// printf("in bot:%d < top:%d\n", bot, top);
			// (*stack) = bot_stack;
			// printr(stack);
			// exit(1);
			bot_stack = push_to_b(top, bot, stack, head, &stack_b); //keep track after pushing
			top_stack = ft_lstfront(bot_stack);
			// printl(&top_stack);
			// exit(1);
			// printf("\n");
		}
		else if (top < bot)
		{
			// printf("in top:%d < bot%d\n", top, bot);
			// printf("this is size:%d\n", ft_lstsize((*stack)));
			(*stack) = top_stack; // need this is since we have to keep track of the stack if it get into bot < top first
			top_stack = push_to_b(top, bot, stack, head, &stack_b);
			// printl(&top_stack);
			// exit(0);
			// printf("after pushing in top\n");
			bot_stack = ft_lstlast(top_stack); //! this will move stack to the last node which won't work properly when pushing.
			// ! do we need the above line if we only need to check the top_stack then assign stack = top_stack?
			// bot_stack = top_stack;
			// printc(&bot_stack);
			// printr(&bot_stack);
			// printr(&bot_stack);
			// printr(&top_stack);
			// exit(1);
			// printf("\n");
		}
		// break ;
		// printf("size:%d\n", ft_lstsize(stack_b));
		// printf("end the loop=========\n");
		i++;
	}
	// printf("out of the lopppppppppppp\n");
	// three_numbers(stack);
	// while (stack_b->next)
	// {
	// 	pa_action(stack, &stack_b);
	// }
	// printf("done process\n");
	three_numbers(stack);
	two_number(&stack_b);
	pa_action(stack, &stack_b);
	pa_action(stack, &stack_b);
	// while (stack_b->content)
	// {
	// 	// printc(&stack_b);
	// 	printf("in stack_b:%lld\n", *((long long *)stack_b->content));
	// 	stack_b = stack_b->next;
	// 	if (stack_b == NULL)
	// 		printf("null\n");
	// 	else
	// 		printf("no null\n");
	// }
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
			{
				(*stack)->index = i++;
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		tmp = tmp->next;
	}
	tmp = head_tmp;
	sort_five(stack, head);

	// while ((*stack))
	// {
	// 	printf("stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
	// 	(*stack) = (*stack)->next;
	// }
}