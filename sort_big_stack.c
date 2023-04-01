#include "push_swap.h"

void	do_radix(t_list **stack, int size, int max_bits, t_list *stack_b)
{
	int	size_b;
	t_swp	pw;

	pw.i = 0;
	while (pw.i < max_bits)
	{
		pw.j = 0;
		while (pw.j < size)
		{
			if ((((int)(*stack)->index >> pw.i)&1) == 1)
				ra_action(stack);
			else
				pb_action(stack, &stack_b);
			pw.j++;
		}
		size_b = ft_lstsize(stack_b);
		while (size_b > 1)
		{
			pa_action(stack, &stack_b);
			size_b--;
		}
		pw.i++;
	}
	free(stack_b);
}

void	sort_radix(t_list **stack, int size)
{
	int	max_num;
	int	max_bits;
	t_list	*stack_b;

	stack_b = ft_lstnew(NULL);
	max_num = size;
	max_bits = 0;
	while ((max_num >> max_bits) != 0) // get the maximum bits to be used in order to check from the most right number
		max_bits++; // In the other word, if the largest bit = 3, the actual bit will have three numbers (ex: 101);
	do_radix(stack, size, max_bits, stack_b);
}

void	sort_big_stack(t_list **stack, int size)
{
	t_swp		pw;

	pw.i = 0;
	pw.tmp = sort_copied_stack(stack);
	pw.head = (*stack);
	pw.head_tmp = pw.tmp;
	while (pw.tmp) // set index to original stack
	{
		while ((*stack))
		{
			if (*((long long *)(*stack)->content) == (long long)pw.tmp->content)
				(*stack)->index = pw.i++;
			(*stack) = (*stack)->next;
		}
		(*stack) = pw.head;
		pw.tmp = pw.tmp->next;
	}
	pw.tmp = pw.head_tmp;
	free_stack(pw.tmp);
	sort_radix(stack, size);
}