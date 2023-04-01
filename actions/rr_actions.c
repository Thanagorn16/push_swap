/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:53:31 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:53:32 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	rra_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_prev;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = (*stack);
	while (tmp->next != (*stack))
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		tmp->prev = tmp_prev;
	}
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_prev;

	tmp = (*stack);
	(*stack) = ft_lstlast((*stack));
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = (*stack);
	while (tmp->next != (*stack))
	{
		tmp_prev = tmp;
		tmp = tmp->next;
		tmp->prev = tmp_prev;
	}
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = ft_lstlast((*stack_a));
	(*stack_a)->next = tmp;
	while (tmp->next != (*stack_a))
		tmp = tmp->next;
	tmp->next = NULL;
	tmp = (*stack_b);
	(*stack_b) = ft_lstlast((*stack_b));
	(*stack_b)->next = tmp;
	while (tmp->next != (*stack_b))
		tmp = tmp->next;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}
