/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:04:14 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/01 15:14:50 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

typedef struct s_split
{
	int		count;
	int		slot;
	size_t	i;
}	t_split;

void	ft_putstr_fd(char *s, int fd);
void	double_free(char **arr);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif