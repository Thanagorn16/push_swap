/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:53:26 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:53:27 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	pa_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "pa\n", 3);
}

void	pb_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);
}
