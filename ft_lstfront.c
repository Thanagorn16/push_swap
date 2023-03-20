#include "push_swap.h"

t_list	*ft_lstfront(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = NULL;
	ptr = lst;
	while (ptr->prev != NULL)
		ptr = ptr->prev;
	return (ptr);
}