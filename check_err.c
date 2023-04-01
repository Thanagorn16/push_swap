/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:05:43 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 14:43:54 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_digit(char **arg, int *size, int *k, int *j)
{
	while ((arg[*k][*j] >= '0' && arg[*k][*j] <= '9')
		|| arg[*k][*j] == '-' || arg[*k][*j] == '+')
	{
		if (ft_strlen(arg[*k]) == 1)
		{
			if (arg[*k][*j] == '-' || arg[*k][*j] == '+')
			{
				double_free(arg);
				is_err();
			}
		}
		(*j)++;
		if (!arg[*k][*j] && arg[*k + 1])
		{
			(*k)++;
			*j = 0;
			(*size)++;
		}
	}
}

int	check_digit(char **str)
{
	char	**arg;
	t_swp	pw;

	pw.i = 1;
	pw.size = 0;
	while (str[pw.i])
	{
		arg = ft_split(str[pw.i], ' ');
		if (!arg[0])
			is_err();
		pw.j = 0;
		pw.k = 0;
		process_digit(arg, &pw.size, &pw.k, &pw.j);
		if ((arg[pw.k][pw.j] != '\0' && arg[pw.k][pw.j] < '0')
			|| (arg[pw.k][pw.j] > '9' && arg[pw.k][pw.j] != '-'
			&& arg[pw.k][pw.j] != '+'))
		{
			double_free(arg);
			is_err();
		}
		double_free(arg);
		pw.size++;
		pw.i++;
	}
	return (pw.size);
}

void	check_repeated_num(long long *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		temp = arr[i];
		j = i;
		while (i < size - 1)
		{
			i++;
			if (temp == arr[i])
				is_err();
		}
		i = j;
		i++;
	}
}

void	check_asceding_order(long long *arr, int size)
{
	int	i;

	i = 0;
	size -= 1;
	while (size > 0)
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			size--;
		}
		else
			break ;
		if (size == 0)
			exit(0);
	}
}

void	check_max_min(long long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			is_err();
		i++;
	}
}
