#include "push_swap.h"

void	is_err()
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int check_digit(char **str) // check while the arguments are still strings
{
	int i;
	int j;
	int k;
	int	size;
	char	**arg;

	i = 1;
	size = 0;
	while (str[i])
	{
		arg = ft_split(str[i], ' ');
		if (arg[k])
		j = 0;
		k = 0;
		while ((arg[k][j] >= '0' && arg[k][j] <= '9') || arg[k][j] == '-' || arg[k][j] == '+')
		{
			if (ft_strlen(arg[k]) == 1) //check if char is a single operator w/o the number after it
			{
				if (arg[k][j] == '-' || arg[k][j] == '+')
				{
					double_free(arg);
					is_err();
				}
			}
			j++;
			if (!arg[k][j] && arg[k + 1]) // check if the end of string and check if there's next str in arg
			{
				k++;
				j = 0;
				size++;
			}
		}
		if ((arg[k][j] != '\0' && arg[k][j] < '0') || (arg[k][j] > '9' && arg[k][j] != '-' && arg[k][j] != '+'))
		{
			double_free(arg);
			is_err();
			// return (-1);
		}
		double_free(arg);
		size++;
		i++;
	}
	return (size);
}
// int check_digit(char **str) // check while the arguments are still strings
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '-' || str[i][j] == '+')
// 		{
// 			if (ft_strlen(str[i]) == 1) //check if char is a single operator w/o the number after it
// 			{
// 				if (str[i][j] == '-' || str[i][j] == '+')
// 				{
// 					double_free(str);
// 					is_err();
// 				}
// 			}
// 			j++;
// 		}
// 		if ((str[i][j] != '\0' && str[i][j] < '0') || (str[i][j] > '9' && str[i][j] != '-' && str[i][j] != '+'))
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }

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
			{
				// double_free_int(arr);
				is_err();
			}
		}
		i = j;
		i++;
	}
}

void	check_asceding_order(long long *arr, int size)
{
	int	i;
	i = 0;
	size -= 1; //should loop less than the actual size by 1
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
		{
			// printf("in ascending\n");
			// double_free_int(arr);
			exit(0);
		}
	}
}

void	check_max_min(long long *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			// double_free_int(arr);
			is_err();
		}
		i++;
	}
}