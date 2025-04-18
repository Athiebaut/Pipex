/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:22:05 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:46:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character `c`
 * (converted to a `char`) in the string pointed to by `s`. The terminating
 * null character is considered part of the string, so if `c` is `\0`,
 * the function will return a pointer to the null terminator.
 *
 * @param s The string to be searched.
 * @param c The character to locate, passed as an `int` but internally
 *          converted to a `char`.
 * @return A pointer to the first occurrence of the character `c` in the
 *         string `s`, or `NULL` if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
