#include "push_swap.h"

int main(int ac, char **av)
{
	int			i;
	int			j;
	int			k;
	int			sz;
	long long	*arr; // keep the value in heap (remain in the memory)
	char		**set;
	t_list		*stack;
	t_list		*tmp;

	if (ac == 1) // case of no parameter
		exit(0);
	if (ac <= 2 && av[1][0] == '\0') // case of "" as an argument
		exit(0);
// check arguments
	sz = check_digit(av);
	if (sz == 0) // case of " " as a parameter
		return (0);
	i = 1;
	k = 0;
	arr = (long long *)malloc(sizeof(long long) * sz);
	if (!arr)
		return (0);
	while (i <= sz) // copy to arr
	{
		j = 0;
		if (av[i]) //split to get arg
		{
			set = ft_split(av[i++], ' ');
			if (!set)
				return (0) ;
		}
		else
			break ;
		while (set[j]) //convert arg to numbers and copy them to arr
			arr[k++] = ft_atoi(set[j++]);
		double_free(set);
	}
	check_asceding_order(arr, sz);
	check_repeated_num(arr, sz);
	// check_repeated_num(arr);
	check_max_min(arr);
	if (sz == 1) // case of 1 element
		exit(0);
	// i = 0;
	// while (arr[i])
	// 	printf("num:%lld\n", arr[i++]);
	// printf("----------------\n");
	// exit(1);

	// create stack
	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (i < sz)
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	// while (stack)
	// {
	// 	printf("stack:%lld\n", *((long long *)stack->content));
	// 	stack = stack->next;
	// }
	// exit(0);
	// three_numbers(&stack);
	// exit(0);
	sort_stack(&stack, sz);
	// printf("end\n");
}