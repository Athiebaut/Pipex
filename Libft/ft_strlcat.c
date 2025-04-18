/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:57 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:06:26 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcat - Concatenates two strings, ensuring null-termination and
 *              preventing buffer overflows.
 *
 * @dst: The destination string to which the source string will be appended.
 *       It must be null-terminated and have enough space to hold the result.
 * @src: The source string to append to the destination string.
 * @size: The total size of the destination buffer, including the null-terminator.
 *
 * This function appends the null-terminated string `src` to the end of `dst`.
 * It ensures that the resulting string in `dst` is null-terminated and does
 * not exceed the buffer size specified by `size`. If the buffer size is too
 * small to hold the concatenated result, the function truncates the result.
 *
 * Return: The total length of the string it tried to create, which is the
 *         initial length of `dst` plus the length of `src`. If the return
 *         value is greater than or equal to `size`, it indicates that
 *         truncation occurred.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tdest;
	size_t	tsrc;

	i = 0;
	tsrc = ft_strlen(src);
	if (size == 0 && !dst)
		return (tsrc);
	tdest = ft_strlen(dst);
	j = tdest;
	if (size <= tdest)
		return (size + tsrc);
	while (src[i] && i < size - tdest - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (tdest + tsrc);
}
