/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:46 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 15:27:25 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_number_b(t_list **stack)
{
	if ((*stack)->index < (*stack)->next->index)
		sb_action(stack);
}

void	two_number(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content)
		sa_action(stack);
}