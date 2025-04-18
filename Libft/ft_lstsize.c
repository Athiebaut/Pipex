/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:14:37 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/09 14:43:47 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstsize.c
 * @brief Counts the number of elements in a linked list.
 *
 * This function traverses a linked list and counts the number of nodes
 * it contains. It starts from the given list head and iterates through
 * each node until it reaches the end of the list.
 *
 * @param lst A pointer to the first node of the linked list.
 * @return The total number of nodes in the linked list.
 */
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*new_lst;

	new_lst = lst;
	count = 0;
	while (new_lst != NULL)
	{
		count++;
		new_lst = new_lst->next;
	}
	return (count);
}
