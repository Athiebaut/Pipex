/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:13:25 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:13:27 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memset.c
 * @brief Implementation of the memset function.
 *
 * This function fills the first `n` bytes of the memory area pointed to by `s`
 * with the constant byte `c`.
 *
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to fill the memory area with. It is passed as an int
 *          but is converted to an unsigned char.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory area `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
