#include "push_swap.h"

void	sort_radix(t_list **stack, int size)
{
	int	i;
	int	j;
	int	max_num;
	int	max_bits;
	int	size_b;
	t_list	*stack_b;

	// create stack b
	stack_b = ft_lstnew(NULL);
	max_num = size;
	max_bits = 0;
	while ((max_num >> max_bits) != 0) // get the maximum bits to be used in order to check from the most right number
		max_bits++; // In the other word, if the largest bit = 3, the actual bit will have three numbers (ex: 101);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((int)(*stack)->index >> i)&1) == 1)
			{
				ra_action(stack);
			}
			else
			{
				pb_action(stack, &stack_b);
			}
			j++;
		}
		size_b = ft_lstsize(stack_b);
		while (size_b > 1)
		{
			pa_action(stack, &stack_b);
			size_b--;
		}
		i++;
	}
	// printl(stack);
	// printf("max_bits:%d\n", max_bits);
	// exit(0);
	// stack = NULL;
}

void	sort_big_stack(t_list **stack, int size)
{
	int			i;
	t_list		*tmp;
	t_list		*head_tmp;
	t_list		*head;

	i = 0;
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
				// printf("print stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		tmp = tmp->next;
	}
	tmp = head_tmp;
	sort_radix(stack, size);
}