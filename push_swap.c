/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:06:20 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:47:12 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	*create_arr(char **av, int sz)
{
	t_swp		pswp;

	pswp.i = 1;
	pswp.k = 0;
	pswp.arr = (long long *)malloc(sizeof(long long) * sz);
	if (!pswp.arr)
		exit(0);
	while (pswp.i <= sz)
	{
		pswp.j = 0;
		if (av[pswp.i])
		{
			pswp.set = ft_split(av[pswp.i++], ' ');
			if (!pswp.set)
				exit(0);
		}
		else
			break ;
		while (pswp.set[pswp.j])
			pswp.arr[pswp.k++] = ft_atoi(pswp.set[pswp.j++]);
		double_free(pswp.set);
	}
	return (pswp.arr);
}

void	do_sort(long long *arr, int sz)
{
	int		i;
	t_list	*stack;
	t_list	*tmp;

	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (i < sz)
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	sort_stack(&stack, sz);
	free_stack(stack);
	free(arr);
}

int	main(int ac, char **av)
{
	int			sz;
	long long	*arr;

	if (ac == 1)
		exit(0);
	if (ac <= 2 && av[1][0] == '\0')
		is_err();
	sz = check_digit(av);
	if (sz == 0)
		return (0);
	arr = create_arr(av, sz);
	check_asceding_order(arr, sz);
	check_repeated_num(arr, sz);
	check_max_min(arr, sz);
	if (sz == 1)
		exit(0);
	do_sort(arr, sz);
}
