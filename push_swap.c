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
	int			size;
	long long	a;
	long long	*arr; // keep the value in heap (remain in the memory)
	long long	*arr2;
	char		**set;
	t_list		*stack;
	t_list		*stack2;
	t_list		*tmp;
	t_list		*tmp2;

	if (ac < 2)
		return (0);

// check arguments
	set = create_double(av);
	set = copy_str(av, set);
	if (check_digit(set) < 0)
		is_err();
	//check size of the set
	size = 0;
	while (set[size])
		size++;
		// printf("size:%s\n", set[size++]);
	size++;
	// convert char to int
	i = 0;
	arr = (long long *)malloc(sizeof(long long) * size);
	while (set[i])
	{
		arr[i] = ft_atoi(set[i]);
		i++;
	}
	double_free(set);
	check_repeated_num(arr);
	check_max_min(arr);
	check_asceding_order(arr);

	i = 0;
	while (arr[i])
		printf("num:%lld\n", arr[i++]);
	printf("----------------\n");

	// create stack
	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (arr[i])
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}

	//test sort
	// three_numbers(&stack);
	five_numbers(stack);

	//test actions
	// rra_action(&stack);
	// while (stack) // check stack
	// {
	// 	printf("stack:%lld\n", *((long long *)stack->content));
	// 	stack = stack->next;
	// }
	// printf("-------------------\n");

	// stack 2
	// i = 0;
	// a = 4;
	// arr2 = (long long *)malloc(sizeof(long long) * 3);
	// while (i < 3)
	// {
	// 	arr2[i] = a;
	// 	i++;
	// 	a++;
	// }
	// arr2[i] = 0;
	// i = 0;
	// while (arr2[i])
	// 	printf("num:%lld\n", arr2[i++]);
	// i = 1;
	// stack2 = ft_lstnew(&arr2[0]);
	// // printf("stack2:%lld\n", *((long long *)stack2->content));
	// while (arr2[i])
	// {
	// 	tmp2 = ft_lstnew(&arr2[i]);
	// 	ft_lstadd_back(&stack2, tmp2);
	// 	i++;
	// }
	// // rrb_action(&stack2);
	// // while (stack2) // check stack
	// // {
	// // 	printf("stack2:%lld\n", *((long long *)stack2->content));
	// // 	stack2 = stack2->next;
	// // }

	// // //ss action
	// pb_action(&stack, &stack2);
	// while (stack) // check stack
	// {
	// 	printf("stack:%lld\n", *((long long *)stack->content));
	// 	stack = stack->next;
	// }
	// printf("================\n");
	// while (stack2) // check stack
	// {
	// 	printf("stack2:%lld\n", *((long long *)stack2->content));
	// 	stack2 = stack2->next;
	// }
	printf("end\n");
}