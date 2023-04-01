/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:36:55 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 13:02:57 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_to_top_b(t_list **stack, t_swp *pw)
{
	t_list	*top_stack;

	top_stack = NULL;
	if (ft_lstsize(pw->stack_b) == 1)
		(*stack) = pw->head;
	while (pw->top > 1 && pw->bot != 1 && pw->top != 1)
	{
		ra_action(stack);
		pw->top--;
	}
	pb_action(stack, &pw->stack_b);
	top_stack = (*stack);
	return (top_stack);
}

t_list	*push_to_b(t_list **stack, t_swp *pw)
{
	t_list	*top_stack;
	t_list	*bot_stack;

	top_stack = NULL;
	bot_stack = NULL;
	if (pw->bot < pw->top)
	{
		if (ft_lstsize(pw->stack_b) == 1)
			(*stack) = pw->head;
		while (pw->bot > 0)
		{
			rra_action(stack);
			pw->bot--;
		}
		bot_stack = ft_lstlast((*stack));
		pb_action(stack, &pw->stack_b);
		return (bot_stack);
	}
	else if (pw->top < pw->bot || pw->bot == pw->top)
		top_stack = push_to_top_b(stack, pw);
	return (top_stack);
}

void	process_sort_five(t_list **stack, t_swp *pw)
{
	pw->i = 0;
	while (pw->i < 2)
	{
		pw->top = 0;
		pw->bot = 0;
		pw->top = search_top(stack);
		if (pw->bot_stack)
			(*stack) = pw->top_stack;
		else
			(*stack) = pw->lst_node;
		pw->bot = search_bot(ft_lstlast((*stack)));
		if (pw->bot < pw->top || pw->bot == pw->top)
		{
			pw->bot_stack = push_to_b(stack, pw);
			pw->top_stack = ft_lstfront(pw->bot_stack);
		}
		else if (pw->top < pw->bot)
		{
			(*stack) = pw->top_stack;
			pw->top_stack = push_to_b(stack, pw);
			pw->bot_stack = ft_lstlast(pw->top_stack);
		}
		pw->i++;
	}
}

void	sort_five(t_list **stack, t_swp *pw)
{
	pw->top_stack = NULL;
	pw->bot_stack = NULL;
	pw->lst_node = ft_lstlast((*stack));
	process_sort_five(stack, pw);
	three_numbers(stack);
	two_number(&pw->stack_b);
	pa_action(stack, &pw->stack_b);
	pa_action(stack, &pw->stack_b);
	free(pw->stack_b);
}

void	five_numbers(t_list **stack)
{
	t_swp		pw;

	pw.i = 1;
	pw.tmp = sort_copied_stack(stack);
	pw.head_tmp = pw.tmp;
	pw.head = (*stack);
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
	pw.stack_b = ft_lstnew(NULL);
	pw.tmp = pw.head_tmp;
	free_stack(pw.tmp);
	sort_five(stack, &pw);
}
