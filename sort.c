#include "push_swap.h"

void	three_numbers(t_list **stack)
{
	long long	top;
	long long	mid;
	long long	bot;

	top = *((long long *)(*stack)->content);
	mid = *((long long *)(*stack)->next->content);
	bot = *((long long *)(*stack)->next->next->content);

	if (top > mid && mid > bot) //case 2
	{
		sa_action(stack);
		rra_action(stack);
	}
	else if (top < mid && top < bot) //case 4
	{
		sa_action(stack);
		ra_action(stack);
	}
	else if (top > mid && top > bot) //case 3
	{
		ra_action(stack);
	}
	else if (top > mid && top < bot) // case 1
		sa_action(stack);
	else if (top < mid && top > bot) //case 5
		rra_action(stack);
}