/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:53:33 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:54:15 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	sa_action(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	write(1, "sa\n", 3);
}

void	sb_action(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	write(1, "sb\n", 3);
}

void	ss_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!stack_a || !stack_b)
		return ;
	tmp_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp_a->next = (*stack_a)->next;
	(*stack_a)->next = tmp_a;
	tmp_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp_b->next = (*stack_b)->next;
	(*stack_b)->next = tmp_b;
	write(1, "ss\n", 3);
}
