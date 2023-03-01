#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	is_err();
void	check_repeated_num();
void	check_asceding_order(long long *arr);
void	check_max_min(long long *arr);
int		check_digit(char **str);

# endif