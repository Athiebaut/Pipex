/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:26:52 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:02:43 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memmove.c
 * @brief Implementation of the ft_memmove function.
 *
 * This function copies `size` bytes from the memory area `source` to the memory
 * area `dest`. The memory areas may overlap, and the copy is performed in a way
 * that ensures the original data in `source` is not corrupted.
 *
 * @param dest Pointer to the destination memory area.
 * @param source Pointer to the source memory area.
 * @param size Number of bytes to copy.
 * @return A pointer to the destination memory area (`dest`).
 *
 * @note If both `dest` and `source` are NULL, the function returns NULL.
 */
void	*ft_memmove(void *dest, const void *source, size_t size)
{
	char	*dst;
	char	*src;
	char	j;
	size_t	i;

	i = 0;
	j = 1;
	dst = (char *)dest;
	src = (char *)source;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		j = -1;
		dst = dst + size - 1;
		src = src + size - 1;
	}
	while (i < size)
	{
		*dst = *src;
		dst = dst + j;
		src = src + j;
		i++;
	}
	return (dest);
}
