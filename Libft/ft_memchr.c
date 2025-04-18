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

/**
 * @file ft_memchr.c
 * @brief Implementation of the ft_memchr function.
 *
 * @details
 * The ft_memchr function locates the first occurrence of a specified byte
 * in a memory block. It searches the first `n` bytes of the memory area
 * pointed to by `s` for the byte `c`. The function returns a pointer to
 * the matching byte, or NULL if the byte is not found within the specified
 * range.
 *
 * @param s Pointer to the memory area to be searched.
 * @param c The byte to search for, passed as an int but interpreted as an
 *          unsigned char.
 * @param n The number of bytes to search in the memory area.
 *
 * @return
 * - A pointer to the first occurrence of the byte `c` in the memory area
 *   pointed to by `s`.
 * - NULL if the byte `c` is not found within the first `n` bytes.
 *
 * @note
 * This function does not check for null pointers. Ensure that the pointer
 * `s` is valid before calling this function.
 */
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
