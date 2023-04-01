/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:53:28 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:53:29 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	ra_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack)
		return ;
	lst_node = ft_lstlast((*stack));
	tmp = (*stack);
	(*stack) = (*stack)->next;
	lst_node->next = tmp;
	tmp->next = NULL;
	tmp->prev = lst_node;
	(*stack)->prev = NULL;
	write(1, "ra\n", 3);
}

void	rb_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack)
		return ;
	lst_node = ft_lstlast((*stack));
	tmp = (*stack);
	(*stack) = (*stack)->next;
	lst_node->next = tmp;
	tmp->next = NULL;
	tmp->prev = lst_node;
	(*stack)->prev = NULL;
	write(1, "rb\n", 3);
}

void	rr_action(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lst_node;

	if (!stack_a || !stack_b)
		return ;
	lst_node = ft_lstlast((*stack_a));
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	lst_node->next = tmp;
	tmp->next = NULL;
	lst_node = ft_lstlast((*stack_b));
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	lst_node->next = tmp;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
