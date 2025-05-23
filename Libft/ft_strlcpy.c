/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:42:02 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 14:29:55 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcpy - Copies up to size - 1 characters from the string src to dst,
 *              null-terminating the result if size is not 0.
 *
 * @dst: The destination buffer where the string will be copied.
 * @src: The source string to be copied.
 * @size: The size of the destination buffer.
 *
 * This function copies at most size - 1 characters from the source string
 * to the destination buffer, ensuring that the result is null-terminated
 * if size is greater than 0. If the size is 0, the destination buffer is
 * not modified. The function returns the total length of the source string,
 * which allows the caller to determine if truncation occurred.
 *
 * Return: The total length of the source string (strlen(src)).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size2;

	size2 = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (size2);
}
