#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*current;

	current = malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	current->content = content;
	current->next = NULL;
	current->prev = NULL; // set prev of the first node as NULL
	return (current);
}