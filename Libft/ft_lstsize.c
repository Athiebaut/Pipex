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
