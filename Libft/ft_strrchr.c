/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:30:52 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:09:04 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr - Locates the last occurrence of a character in a string.
 *
 * @s: The string to be searched.
 * @c: The character to locate, passed as an int but interpreted as a char.
 *
 * This function searches for the last occurrence of the character `c` in the
 * string `s`. The terminating null byte is considered part of the string, so
 * if `c` is '\0', the function will locate the null terminator.
 *
 * Return: A pointer to the last occurrence of the character `c` in the string
 *         `s`, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
