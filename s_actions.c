#include "push_swap.h"

void	sa_action(t_list **stack)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!stack)
		return ;
	// ptr = *stack; // a 3
	tmp = ptr->next; // keep -2
	// swap
	printf("here:%lld\n", *((long long *)tmp->content));
	// ptr = tmp;
	(*stack) = tmp;
	printf("here:%lld\n", *((long long *)(*stack)->content));
	printf("here:%lld\n", *((long long *)ptr->content));
	// ptr = ptr->next; // 3 == -2
	// tmp->next = ptr->next; // 3 -> 1
	// ptr->next = tmp; //
}

// void	sa_action(t_list **stack)
// {
// 	t_list	*tmp;
// 	t_list	*ptr;

// 	if (!stack)
// 		return ;
// 	ptr = *stack; // a 3
// 	tmp = ptr->next; // keep -2
// 	// swap
// 	printf("here:%lld\n", *((long long *)tmp->content));
// 	ptr = tmp;
// 	printf("here:%lld\n", *((long long *)ptr->content));
// 	// ptr = ptr->next; // 3 == -2
// 	// tmp->next = ptr->next; // 3 -> 1
// 	// ptr->next = tmp; //
// }
