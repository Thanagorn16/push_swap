#include "push_swap.h"

void	sort_stack(t_list **stack, int size)
{
	if (size == 3)
		three_numbers(stack);
	else if (size == 5)
		five_numbers(stack);
	// printl(stack);
}