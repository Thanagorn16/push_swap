#include "push_swap.h"

char    **create_double(char **av)
{
	int i;
	int j;
	int count;
	char    **temp;
	char    **set;

	i = 1;
	j = 0;
	count = 0;
	while (av[i]) // big malloc // this method check all the arguments at once that's why 2d array is made
	{
		j = 0;
		temp = ft_split(av[i], ' ');
		while (temp[j] != NULL)
		{
			j++;
			count++; //count the set of numbers after split
		}
		i++;
	}
	set = (char **)malloc(sizeof(char *) * count);
	double_free(temp);
	if (!set)
		return (NULL);
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
	set[j] = NULL; // set the end of the array
	// free(str); // freeing this will make the program not able to get all the string
	return (set);
}

int main(int ac, char **av)
{
	int			i;
	long long	*arr; // keep the value in heap (remain in the memory)
	char		**set;
	t_list		*stack;
	t_list		*tmp;

	if (ac < 2)
		return (0);

// check arguments
	set = create_double(av);
	set = copy_str(av, set);
	if (check_digit(set) < 0)
		is_err();
	// convert char to int
	i = 0;
	arr = (long long *)malloc(sizeof(long long));
	while (set[i])
	{
		arr[i] = ft_atoi(set[i]);
		i++;
	}
	double_free(set);

	i = 0; //check int malloc
	while (arr[i])
		printf("%lld\n", arr[i++]);
	printf("-------------\n");

	check_repeated_num(arr);
	check_max_min(arr);
	check_asceding_order(arr);

	// create stack
	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (arr[i])
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	sa_action(&stack);
	// while (stack) // check stack
	// {
	// 	printf("stack:%lld\n", *((long long *)stack->content));
	// 	stack = stack->next;
	// }

	printf("end\n");
}