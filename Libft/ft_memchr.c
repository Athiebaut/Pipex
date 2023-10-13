/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:38:03 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:05:05 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	nb;
	size_t			i;

	str = (unsigned char *)s;
	nb = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == nb)
			return (str + i);
		i++;
	}
	return (0);
}
