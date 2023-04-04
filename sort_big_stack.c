/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:26 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/04 12:14:10 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_radix(t_list **stack, int size, int max_bits, t_list *stack_b)
{
	int		size_b;
	t_swp	pw;

	pw.i = 0;
	while (pw.i < max_bits)
	{
		pw.j = 0;
		while (pw.j < size)
		{
			if ((((int)(*stack)->index >> pw.i) & 1) == 1)
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
	int		max_num;
	int		max_bits;
	t_list	*stack_b;

	stack_b = ft_lstnew(NULL);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	do_radix(stack, size, max_bits, stack_b);
}

void	sort_big_stack(t_list **stack, int size)
{
	t_swp		pw;

	pw.i = 0;
	pw.tmp = sort_copied_stack(stack);
	pw.head = (*stack);
	pw.head_tmp = pw.tmp;
	while (pw.tmp)
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
