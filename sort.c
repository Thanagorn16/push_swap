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

	i = 0;
	tmp = (*stack);

	
}
// void	five_numbers(t_list **stack)
// {
// 	long long	num;
// 	int			i;
// 	t_list		*stack_tmp;
// 	t_list		*tmp;

// 	i = 0;
// 	stack_tmp = (*stack);
// 	tmp = stack_tmp;
// 	*((long long *)tmp->content) = (long long) 22;
// 	while (i > 0)
// 	{
// 		if ((*(long long *)tmp->content) > *((long long *)tmp->next->content))
// 		{
// 			num = *((long long *)tmp->content);
// 			// printf("keep num:%lld\n", num);
// 			// printf("current:%lld\n", *((long long *)tmp->content));
// 			// printf("next node:%lld\n", *((long long *)tmp->next->content));
// 			// printf("--------------");
// 			tmp->content = tmp->next->content;
// 			// printf("change to:%lld\n", *((long long *)tmp->content));
// 			*((long long *)tmp->next->content) = num;
// 			// printf("next:%lld\n", *((long long *)tmp->next->content));
// 			// printf("------------ done --------\n");
// 		}
// 		i++;
// 		printf("i:%d\n", i);
// 		if (i == ft_lstsize(stack_tmp))
// 		{
// 			// printf("i:%d\n", i);
// 			tmp->next = NULL;
// 		}
// 		tmp = tmp->next;
// 		// i++;
// 		// printf("out:%lld\n", *((long long *)tmp->next->content));
// 		// stack_tmp = stack_tmp->next;
// 	}

// 	printf("before\n");
// 	while (stack_tmp)
// 	{
// 		printf("tmp:%lld\n", *((long long *)stack_tmp->content));
// 		stack_tmp = stack_tmp->next;
// 	}
// 	while (tmp)
// 	{
// 		printf("mytmp:%lld\n", *((long long *)tmp->content));
// 		tmp = tmp->next;
// 	}
// }