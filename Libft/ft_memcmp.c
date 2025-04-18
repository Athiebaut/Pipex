/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:56:19 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 13:00:56 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first 'size' bytes of two memory areas.
 * 
 * This function compares the memory areas pointed to by 'str1' and 'str2'.
 * It returns an integer less than, equal to, or greater than zero if the first
 * differing byte in 'str1' is found to be less than, equal to, or greater than
 * the corresponding byte in 'str2'.
 * 
 * @param str1 Pointer to the first memory area.
 * @param str2 Pointer to the second memory area.
 * @param size Number of bytes to compare.
 * 
 * @return An integer indicating the result of the comparison:
 *         - 0 if the memory areas are equal.
 *         - A positive value if the first differing byte in 'str1' is greater
 *           than the corresponding byte in 'str2'.
 *         - A negative value if the first differing byte in 'str1' is less
 *           than the corresponding byte in 'str2'.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (size == 0)
		return (0);
	while (*s1 == *s2 && size - 1 > 0)
	{
		s1++;
		s2++;
		size--;
	}
	return ((int)(*s1 - *s2));
}
