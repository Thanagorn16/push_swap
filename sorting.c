/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:48 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 15:23:32 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack, int size)
{
	if (size == 2)
		two_number(stack);
	else if (size == 3)
		three_numbers(stack);
	else if (size == 5)
		five_numbers(stack);
	else
		sort_big_stack(stack, size);
}
