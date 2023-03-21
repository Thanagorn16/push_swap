#include "push_swap.h"

void	two_number(t_list **stack)
{
	if ((*stack)->index < (*stack)->next->index)
		sb_action(stack);
}