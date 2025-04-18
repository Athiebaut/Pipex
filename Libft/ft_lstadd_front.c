/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:10:39 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 14:39:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element at the beginning of a linked list.
 * 
 * This function takes a pointer to the head of a linked list and a new element,
 * and inserts the new element at the front of the list. If either the list or 
 * the new element is NULL, the function does nothing.
 * 
 * @param lst A double pointer to the head of the linked list.
 * @param new A pointer to the new element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
