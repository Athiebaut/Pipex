/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:32:59 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 16:33:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a single element of a linked list using a specified
 *        deletion function and frees its memory.
 * 
 * @param lst The element of the list to delete.
 * @param del A pointer to a function used to delete the content of the element.
 *            This function should handle the deallocation of the content.
 * 
 * @note If either `lst` or `del` is NULL, the function does nothing.
 *       The memory of the list element itself is freed after its content
 *       is deleted.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free (lst);
}
