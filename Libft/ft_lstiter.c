/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:51:21 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 17:51:22 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstiter.c
 * @brief Applies a function to each element of a linked list.
 *
 * This function iterates through each node of a linked list and applies the
 * given function to the content of each node.
 *
 * @param lst A pointer to the first node of the linked list.
 * @param f A pointer to the function to apply to each node's content.
 *
 * @note If the list is empty (lst is NULL), the function does nothing.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (!lst)
		return ;
	node = lst;
	while (node != NULL)
	{
		(*f)(node->content);
		node = node->next;
	}
}
