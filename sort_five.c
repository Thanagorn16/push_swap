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

void	sort_five(t_list **stack, t_list *head)
{
	int	top;
	int	bot;
	int	i;
	t_list	*stack_b;
	t_list	*lst_node;
	t_list	*top_stack;
	t_list	*bot_stack;

	// check index
	stack_b = ft_lstnew(NULL);
	lst_node = ft_lstlast((*stack));
	i = 0;
	// while (ft_lstsize(stack_b) < 2)
	while (i < 2)
	{
		printf("start size:%d\n", ft_lstsize(stack_b));
		top = 0;
		bot = 0;
		if (top_stack->next) // continue stack from the tracker
		{
			(*stack) = top_stack;
			printf("get TOP_stack in:%d\n", i);
			// printl(stack);
		}
		while ((*stack)) // traverse from top
		{
			// printf("loop no:%d\n", i);
			if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
			{
				// printc(stack);
				top++;
				printf("top:%d\n", top);
				break ;
			}
			top++;
			(*stack) = (*stack)->next;
		}
		top_stack = (*stack); // keep track of the stack start from the top
		if (bot_stack->prev) // continue stack from the tracker
		{
			(*stack) = bot_stack;
			// printf("get BOT_stack in:%d\n", i);
		}
		else
			(*stack) = lst_node;
		while ((*stack)) // traverse from bot
		{
			printf("BOT search\n");
			if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
			{
				bot++;
				printf("bot:%d\n", bot);
				printc(stack);
				break ;
			}
			bot++;
			(*stack) = (*stack)->prev;
		}
		bot_stack = (*stack); // keep track of the stack start from the bottom
		if (bot < top)
		{
			(*stack) = head; // get original stack to execute the actions
			while (bot > 0)
			{
				rra_action(stack);
				bot--;
			}
			pb_action(stack, &stack_b);
			bot_stack = ft_lstlast((*stack)); // keep track after the actions
			// printf("in bot < top\n");
		}
		else if (top < bot)
		{
			(*stack) = head;
			while (top > 0)
			{
				ra_action(stack);
				top--;
			}
			pb_action(stack, &stack_b);
			top_stack = (*stack);
			printf("in top < bot\n");
		}
		// break ;
		// printf("size:%d\n", ft_lstsize(stack_b));
		// printf("end the loop=========\n");
		i++;
	}
	while (stack_b->content)
	{
		// printc(&stack_b);
		printf("in stack_b:%lld\n", *((long long *)stack_b->content));
		stack_b = stack_b->next;
		if (stack_b == NULL)
			printf("null\n");
		else
			printf("no null\n");
	}
	// printl(&stack_b);
	// (*stack) = head;
	// printf("top:%d\n", top);
	// printf("bot:%d\n", bot);
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
	// check index
	sort_five(stack, head);

	// t_list	*stack_b;
	// stack_b = ft_lstnew(NULL);
	// pb_action(stack, &stack_b);
	// pb_action(stack, &stack_b);

	// i = 0;
	// while ((*stack))
	// {
	// 	if ((*stack)->index == 1) //end the search
	// 	{
	// 		i++;
	// 		break ;
	// 	}
	// 	i++;
	// 	(*stack) = (*stack)->next;
	// }
	// (*stack) = head;
	// printf("index:%d\n", i);

	//test
	// printl(&stack_b);
	// printc(&stack_b);
	// stack_b = stack_b->next;
	// printc(&stack_b);
	// stack_b = stack_b->next;
	// printc(&stack_b);
	// printl(stack);
	// while (tmp)
	// {
	// 	printf("new:tmp:%lld\n", (long long)tmp->content);
	// 	tmp = tmp->next;
	// }
	while ((*stack))
	{
		printf("stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
		(*stack) = (*stack)->next;
	}
}