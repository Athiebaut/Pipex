/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:45:30 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 14:45:31 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstlast - Returns the last element of a linked list.
 *
 * @lst: A pointer to the first element of the linked list.
 *
 * This function iterates through the linked list until it reaches
 * the last element, which is identified by its `next` pointer being NULL.
 * If the list is empty (i.e., @lst is NULL), the function returns NULL.
 *
 * Return: A pointer to the last element of the linked list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
