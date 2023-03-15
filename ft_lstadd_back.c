#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL) // if the list is empty
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL) // traverse through the list if next != NULL
		ptr = ptr->next;
	if (ptr)
	{
		(ptr)->next = new;
		(ptr)->next->prev = ptr;
	}
}