/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:56 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_elem, size_t size)
{
	void	*tab;

	if (nb_elem > ((sizeof(char) * 2147483424) / size))
		return (NULL);
	tab = (void *)malloc(nb_elem * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nb_elem * size));
	return (tab);
}
