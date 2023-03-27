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
		// printf("here:%s\n", arg[0]);
		if (!arg[0])
		{
			// printf("11111111\n");
			return (0);
		}
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
		}
		double_free(arg);
		size++;
		i++;
	}
	return (size);
}

void	check_repeated_num(long long *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	// while (arr[i])
	// printf("size:%d\n", size);
	while (i < size)
	{
		temp = arr[i];
		j = i;
		// while (arr[i])
		while (i < size - 1)
		{
			i++;
			if (temp == arr[i])
			{
				// printf("yes\n");
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
			exit(0);
		}
	}
}

void	check_max_min(long long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			is_err();
		}
		i++;
	}
}