/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:20:55 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 17:17:50 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts a substring from a given string.
 *
 * This function allocates (with malloc) and returns a substring from the string `s`.
 * The substring begins at index `start` and is of maximum length `len`.
 *
 * @param s The input string from which the substring is extracted.
 * @param start The starting index of the substring in the string `s`.
 * @param len The maximum length of the substring to extract.
 * 
 * @return A pointer to the newly allocated substring, or NULL if the allocation fails
 *         or if the input string `s` is NULL.
 *
 * @note If `start` is greater than the length of `s`, the function returns an empty string.
 *       If `len` exceeds the remaining characters in `s` starting from `start`, the function
 *       adjusts `len` to fit within the bounds of the string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	str = (char *)malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	if (start <= slen)
		ft_strlcpy(str, s + start, len + 1);
	else
		str[0] = '\0';
	return (str);
}
