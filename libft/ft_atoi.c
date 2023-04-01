/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:04:31 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 15:14:38 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_operator(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (i > 1)
			is_err();
	}
}

long long	ft_atoi(const char *str)
{
	long long	temp;
	int	nev;
	int	i;

	i = 0;
	nev = 0;
	temp = 0;
	check_operator(str);
	i = 0;
	if (str[i] != '\0' && str[i] == '-')
	{
		nev = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		temp = (temp * 10) + (str[i++] - '0');
	if (str[i] == '+' || str[i] == '-')
		is_err();
	if (nev == 1)
		return (-temp);
	return (temp);
}
