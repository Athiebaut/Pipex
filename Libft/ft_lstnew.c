/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:05:49 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 14:08:34 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc) and initializes a new element of a linked list.
 * 
 * @param content The content to store in the new element.
 * 
 * @return A pointer to the new element, or NULL if the allocation fails.
 * 
 * The function creates a new linked list element (t_list) and initializes its
 * content with the provided value. The 'next' pointer of the new element is
 * set to NULL.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
