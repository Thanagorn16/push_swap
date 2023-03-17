#include "push_swap.h"

void	printc(t_list **stack)
{
	if ((*stack) == NULL)
	{
		printf("out of node\n");
		return ;
	}
	printf("here:%lld\n", *((long long *)(*stack)->content));
}
void	printl(t_list **stack)
{
	while ((*stack)->content)
	{
		printf("print stack:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
		(*stack) = (*stack)->next;
		if ((*stack) == NULL)
			break ;
	}
}

void	printr(t_list **stack)
{
	while ((*stack)->content)
	{
		printf("print prev:%lld / index:%d\n", *((long long *)(*stack)->content), (int)(*stack)->index);
		(*stack) = (*stack)->prev;
		if ((*stack) == NULL)
			break ;
	}
}