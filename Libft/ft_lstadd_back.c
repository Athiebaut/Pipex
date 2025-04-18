/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:22:09 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 16:22:10 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element to the end of a linked list.
 * 
 * This function takes a pointer to the first element of a linked list and a 
 * new element to be added. If the list is not empty, the new element is added 
 * to the end of the list. If the list is empty, the new element becomes the 
 * first element of the list.
 * 
 * @param lst A double pointer to the first element of the linked list.
 *            If the list is empty, *lst will be updated to point to the new element.
 * @param new A pointer to the new element to be added to the list.
 *            The `next` pointer of this element should be initialized to NULL.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
