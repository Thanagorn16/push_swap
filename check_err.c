#include "push_swap.h"

void	is_err()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int check_digit(char **str) // check while the arguments are still strings
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] >= '0' && str[i][j] <= '9' || str[i][j] == '-' || str[i][j] == '+')
		{
			if (ft_strlen(str[i]) == 1) //check if char is a single operator w/o the number after it
			{
				if (str[i][j] == '-' || str[i][j] == '+')
					is_err();
			}
			j++;
		}
		if (str[i][j] != '\0' && str[i][j] < '0' || str[i][j] > '9' && str[i][j] != '-' && str[i][j] != '+')
			return (-1);
		i++;
	}
	return (0);
}

void	check_repeated_num(long long *arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (arr[i])
	{
		temp = arr[i];
		j = i;
		while (arr[i])
		{
			i++;
			if (temp == arr[i])
				is_err();
		}
		i = j;
		i++;
	}
}

void	check_asceding_order(long long *arr)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (arr[size])
		size++;
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
			exit(2);
	}
}

void	check_max_min(long long *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			is_err();
		i++;
	}
}