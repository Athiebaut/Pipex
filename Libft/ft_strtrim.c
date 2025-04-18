/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:50:28 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 13:14:00 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is present in a specified set of characters.
 *
 * This function iterates through the provided set of characters and determines
 * whether the given character `c` exists within the set.
 *
 * @param c The character to check.
 * @param set A null-terminated string representing the set of characters to check against.
 * @return int Returns 1 if the character `c` is found in the set, otherwise returns 0.
 */
static int	ft_check(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @file ft_strtrim.c
 * @brief Trims characters from the beginning and end of a string based on a set of characters.
 *
 * This function removes all characters from the beginning and end of the input string `s1`
 * that are present in the character set `set`. The resulting trimmed string is dynamically
 * allocated and returned.
 *
 * @param s1 The input string to be trimmed. Must be a null-terminated string.
 * @param set The set of characters to trim from the beginning and end of `s1`.
 *            Must be a null-terminated string.
 * @return A newly allocated string with the trimmed content. If memory allocation fails
 *         or if either `s1` or `set` is NULL, the function returns NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 *
 * @dependencies
 * - ft_check: A helper function that checks if a character is present in the set.
 * - ft_strlen: A helper function that calculates the length of a string.
 * - ft_strlcpy: A helper function that copies a string with a specified size limit.
 *
 * @example
 * char *s1 = "   Hello, World!   ";
 * char *set = " ";
 * char *trimmed = ft_strtrim(s1, set);
 * // trimmed now contains "Hello, World!"
 * free(trimmed);
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check(*s1, (char *)set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_check(s1[len - 1], (char *)set) == 1)
			len--;
		else
			break ;
	}
	str = (char *)malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
