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
	t_list	*bef;
	t_list	*stack_b;
	t_list	*lst_node;

	// check index
	stack_b = ft_lstnew(NULL);
	// while ((*stack_b))
	// {
	// 	// printc(&stack_b);
	// 	printf("here:%lld\n", (long long)(*stack_b)->content);
	// 	(*stack_b) = (*stack_b)->next;
	// }
	lst_node = ft_lstlast((*stack));
	while (ft_lstsize(stack_b) < 2)
	{
		top = 0;
		bot = 0;
		// (*stack) = head;
		while ((*stack)) // traverse from top
		{
			// printc(stack);
			if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
			{
				// printc(stack);
				printf("run top\n");
				top++;
				break ;
			}
			top++;
			(*stack) = (*stack)->next;
		}
		(*stack) = lst_node;
		while ((*stack)) // traverse from bot
		{
			// printf("run bot\n");
			if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
			{
				printf("run bot\n");
				bot++;
				break ;
			}
			bot++;
			(*stack) = (*stack)->prev;
		}
		// (*stack) = head;
		// break ;
		// printf("top:%d\n", top);
		// printf("bot:%d\n", bot);
		if (bot < top)
		{
			while (bot > 0)
			{
				rra_action(stack);
				bot--;
			}
			printf("in bot < top\n");
			pb_action(stack, &stack_b);
		}
		else if (top < bot)
		{
			while (top > 0)
			{
				ra_action(stack);
				top--;
			}
			printf("in top < bot\n");
			pb_action(stack, &stack_b);
		}
		// break ;
		printf("size:%d\n", ft_lstsize(stack_b));
		// while (stack_b)
		// {
		// 	printf("here:%lld\n", *((long long *)stack_b->content));
		// 	stack_b = stack_b->next;
		// }
		// exit(1);
	}
	// while (stack_b)
	// {
	// 	// printc(&stack_b);
	// 	printf("here:%lld\n", *((long long *)stack_b->content));
	// 	stack_b = stack_b->next;
	// 	if (stack_b == NULL)
	// 		printf("null\n");
	// 	else
	// 		printf("no null\n");
	// }
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