/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:05:31 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 18:05:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list by applying a function to each element of an existing list.
 * 
 * This function iterates through the given linked list `lst`, applies the function `f`
 * to the content of each node, and creates a new list with the results. If memory allocation
 * fails at any point, the `del` function is used to free the memory of the new list.
 * 
 * @param lst The pointer to the first node of the linked list to be iterated.
 * @param f The function to apply to the content of each node.
 * @param del The function to free the memory of a node's content in case of failure.
 * 
 * @return A pointer to the first node of the new list, or NULL if memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
