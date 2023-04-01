/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:21:33 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 13:21:34 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack, long long top, long long mid, long long bot)
{
	if (top < mid && mid < bot)
		return ;
	if (top > mid && mid > bot)
	{
		sa_action(stack);
		rra_action(stack);
	}
	else if (top < mid && top < bot)
	{
		sa_action(stack);
		ra_action(stack);
	}
	else if (top > mid && top > bot)
		ra_action(stack);
	else if (top > mid && top < bot)
		sa_action(stack);
	else if (top < mid && top > bot)
		rra_action(stack);
}

void	three_numbers(t_list **stack)
{
	long long	top;
	long long	mid;
	long long	bot;

	top = *((long long *)(*stack)->content);
	mid = *((long long *)(*stack)->next->content);
	bot = *((long long *)(*stack)->next->next->content);
	sort_three(stack, top, mid, bot);
}
