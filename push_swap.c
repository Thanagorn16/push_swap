#include "push_swap.h"

long long	*create_arr(char **av, int sz)
{
	t_swp		pswp;

	pswp.i = 1;
	pswp.k = 0;
	pswp.arr = (long long *)malloc(sizeof(long long) * sz);
	if (!pswp.arr)
		exit(0);
	while (pswp.i <= sz) // copy to arr
	{
		pswp.j = 0;
		if (av[pswp.i]) //split to get arg
		{
			pswp.set = ft_split(av[pswp.i++], ' ');
			if (!pswp.set)
				exit(0) ;
		}
		else
			break ;
		while (pswp.set[pswp.j]) //convert arg to numbers and copy them to arr
			pswp.arr[pswp.k++] = ft_atoi(pswp.set[pswp.j++]);
		double_free(pswp.set);
	}
	return (pswp.arr);
}

void	do_sort(long long *arr, int sz)
{
	int	i;
	t_list		*stack;
	t_list		*tmp;

	i = 1;
	stack = ft_lstnew(&arr[0]);
	while (i < sz)
	{
		tmp = ft_lstnew(&arr[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	sort_stack(&stack, sz);
}

int main(int ac, char **av)
{
	int			sz;
	long long	*arr; // keep the value in heap (remain in the memory)

	if (ac == 1) // case of no parameter
		exit(0);
	if (ac <= 2 && av[1][0] == '\0') // case of "" as an argument
		exit(0);
	sz = check_digit(av);
	if (sz == 0) // case of " " as a parameter
		return (0);
	arr = create_arr(av, sz);
	check_asceding_order(arr, sz);
	check_repeated_num(arr, sz);
	check_max_min(arr, sz);
	if (sz == 1) // case of 1 element
		exit(0);
	do_sort(arr, sz);
}