/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:06:31 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 17:42:54 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strnstr - Locates the first occurrence of the null-terminated string
 *              `to_find` within the string `str`, searching at most `len`
 *              characters.
 *
 * @param str: The string to be searched.
 * @param to_find: The substring to locate within `str`.
 * @param len: The maximum number of characters to search in `str`.
 *
 * @return A pointer to the first occurrence of `to_find` in `str` if found,
 *         or NULL if `to_find` is not found within the first `len` characters.
 *         If `to_find` is an empty string, the function returns `str`.
 *
 * Note:
 * - If both `str` and `len` are NULL, the function returns NULL.
 * - The search stops when `len` characters are checked or the end of `str`
 *   is reached, whichever comes first.
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (0);
	if (to_find == str)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (i + j) < len)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)(str + i));
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
