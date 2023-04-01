/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:22 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:48:16 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "actions/action.h"

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_swp
{
	int				i;
	int				j;
	int				k;
	int				size;
	int				top;
	int				bot;
	long long		*arr;
	char			**set;
	t_list			*head;
	t_list			*head_tmp;
	t_list			*tmp;
	t_list			*stack_b;
	t_list			*lst_node;
	t_list			*top_stack;
	t_list			*bot_stack;
}	t_swp;

void	is_err(void);
void	check_repeated_num(long long *arr, int size);
void	check_asceding_order(long long *arr, int size);
void	check_max_min(long long *arr, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	two_number(t_list **stack);
void	three_numbers(t_list **stack);
void	five_numbers(t_list **stack);
void	sort_big_stack(t_list **stack, int size);
void	sort_stack(t_list **stack, int size);
void	sort_tmp(t_list *tmp);
void	double_free_int(long long *arr);
void	free_stack(t_list *stack);
int		check_digit(char **str);
int		ft_lstsize(t_list *lst);
int		search_top(t_list **stack);
int		search_bot(t_list *stack);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfront(t_list *lst);
t_list	*sort_copied_stack(t_list **stack);

#endif