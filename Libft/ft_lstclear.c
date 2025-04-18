/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:37:32 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 16:37:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstclear.c
 * @brief Clears and frees the memory of a linked list.
 *
 * This function iterates through a linked list, freeing the memory of each
 * node using the provided `del` function and the `ft_lstdelone` function.
 * After the function is executed, the pointer to the list is set to NULL.
 *
 * @param lst A double pointer to the first node of the linked list.
 *            If the list is empty or NULL, the function does nothing.
 * @param del A pointer to a function used to free the content of each node.
 *            If NULL, the function does nothing.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
}
