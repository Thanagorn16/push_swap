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
	int	i;
	t_list	*stack_b;

	// check index
	i = 0;
	// stack_b = ft_lstnew(NULL);
	while (ft_lstsize(stack_b) < 2)
	{
		while ((*stack))
		{
			if ((*stack)->index == 1 || (*stack)->index == 2) //get index1 position
			{
				i++;
				// push_to_b(stack, stack_b, i);
			}
			i++;
			(*stack) = (*stack)->next;
		}
		// (*stack) = head;
	}
	// (*stack) = head;
	printf("index:%d\n", i);
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
	// sort_five(stack, head);
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
	// while (tmp)
	// {
	// 	printf("new:tmp:%lld\n", (long long)tmp->content);
	// 	tmp = tmp->next;
	// }
	// while ((*stack))
	// {
	// 	printf("stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
	// 	(*stack) = (*stack)->prev;
	// }
	t_list	*my_lst;
	t_list	*my_lst2;

	my_lst = ft_lstnew((void *)12);
	my_lst2 = ft_lstnew((void *)13);
	printf("lst:%d\n", (int)my_lst->content);
	printf("lst:%d\n", (int)my_lst->next);
	printf("lst:%d\n", (int)my_lst->prev);
	if (my_lst->prev == NULL)
		printf("yes\n");
	ft_lstadd_back(&my_lst, my_lst2);
	while (my_lst)
	{
		// printf("in loop\n");
		printf("lst:%d\n", (int)my_lst->content);
		// printf("lst:%d\n", (int)my_lst->prev->content);
		my_lst = my_lst->next;
		printf("lst:%d\n", (int)my_lst->prev->content);
		// my_lst = my_lst->next;
	// if (my_lst->prev == NULL)
	// 	printf("this is null\n");
	}
	if (my_lst == NULL)
		printf("this is null\n");
	if (!my_lst)
		printf("still null\n");
	my_lst = my_lst->prev;
	printf("lst:%d\n", (int)my_lst->content);

}