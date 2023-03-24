#include "push_swap.h"

char    **create_double(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**temp;
	char	**set;

	i = 1;
	j = 0;
	count = 0;
	while (av[i]) // big malloc // this method check all the arguments at once that's why 2d array is made
	{
		j = 0;
		temp = ft_split(av[i], ' '); //split this way may lead to leak. Need to find another way
		while (temp[j] != NULL)
		{
			j++;
			count++; //count the set of numbers after split
		}
		i++;
	}
	set = (char **)malloc(sizeof(char *) * count);
	if (!set)
		return (NULL);
	double_free(temp);
	return (set);
}

char	**copy_str(char **av, char **set)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;
	char	**temp;

	i = 1;
	j = 0;
	while (av[i])
	{
		k = 0;
		if (av[i]) //split
			temp = ft_split(av[i], ' ');
		while (temp[k] != NULL) // copy the splitted nums to malloc
		{
			str = ft_strdup(temp[k]);
			set[j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1); // small malloc
			if (!set[j])
				return (NULL);
			len = 0;
			while (str[len])
			{
				set[j][len] = str[len];
				len++;
			}
			set[j][len] = '\0';
			j++;
			k++; // this is used to get out of the loop
		}
		i++;
	}
	double_free(temp);
	set[j] = NULL; // set the end of the array
	// free(str); // freeing this will make the program not able to get all the string
	return (set);
}

int	get_size(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		// if (strlen(av[i]) > 1)
		// {

		// }
		while ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-' || av[i][j] == '+')
		{
			
			j++;
		}
		if ((av[i][j] != '\0' && av[i][j] < '0') || (av[i][j] > '9' && av[i][j] != '-' && av[i][j] != '+'))
			return (-1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int			i;
	int			size;
	long long	*arr; // keep the value in heap (remain in the memory)
	char		**set;
	t_list		*stack;
	t_list		*tmp;

	if (ac < 2)
		return (0);
	// printf("len:%zu\n", ft_strlen(av[1]));
	// exit(1);
// check arguments
	set = create_double(av);
	set = copy_str(av, set);
	if (check_digit(set) < 0)
	{
		double_free(set);
		is_err();
	}
	//check size of the set
	size = 0;
	while (set[size])
		size++;
	size++;
	// convert char to int
	i = 0;
	arr = (long long *)malloc(sizeof(long long) * size);
	if (!arr)
		return (0);
	while (set[i])
	{
		arr[i] = ft_atoi(set[i]);
		i++;
	}
	double_free(set);
	size--;
	check_repeated_num(arr);
	check_max_min(arr);
	check_asceding_order(arr, size);
	// i = 0;
	// while (arr[i])
	// 	printf("num:%lld\n", arr[i++]);
	// printf("----------------\n");

	// create stack
	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (arr[i])
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	// double_free_int(arr);
	// printf("%d\n", size);
	// exit(0);
	sort_stack(&stack, size - 1);
	// printf("end\n");
}