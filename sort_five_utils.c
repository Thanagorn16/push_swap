/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:35 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 13:19:59 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_sorting(t_list *tmp, t_list *head)
{
	while (tmp)
	{
		if ((long long)tmp->content > (long long)tmp->next->content)
		{
			tmp = head;
			sort_tmp(tmp);
		}
		tmp = tmp->next;
		if (tmp->next == NULL)
			break ;
	}
}

void	sort_tmp(t_list *tmp)
{
	long long	tmp_num;
	t_list		*head;

	head = tmp;
	while (tmp)
	{
		if ((long long)tmp->content > (long long)tmp->next->content)
		{
			tmp_num = (long long)tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = (void *) tmp_num;
		}
		tmp = tmp->next;
		if (tmp->next == NULL)
		{
			tmp = head;
			keep_sorting(tmp, head);
			break ;
		}
	}
}

t_list	*sort_copied_stack(t_list **stack)
{
	long long	num;
	t_list		*tmp;
	t_list		*head;
	t_list		*new;

	head = (*stack);
	tmp = NULL;
	while ((*stack))
	{
		num = *((long long *)(*stack)->content);
		new = ft_lstnew((void *)num);
		ft_lstadd_back(&tmp, new);
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
	head = tmp;
	sort_tmp(tmp);
	tmp = head;
	return (tmp);
}

int	search_top(t_list **stack)
{
	int	top;

	top = 0;
	while ((*stack))
	{
		if ((*stack)->index == 1 || (*stack)->index == 2)
		{
			top++;
			break ;
		}
		top++;
		(*stack) = (*stack)->next;
	}
	return (top);
}

int	search_bot(t_list *stack)
{
	int	bot;

	bot = 0;
	while (stack)
	{
		if (stack->index == 1 || stack->index == 2)
		{
			bot++;
			break ;
		}
		bot++;
		stack = stack->prev;
	}
	return (bot);
}
