/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:45:56 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 18:31:31 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strdup.c
 * @brief Implementation of the ft_strdup function.
 *
 * This function duplicates a given string by allocating memory for a new string
 * and copying the contents of the source string into it.
 *
 * @param src The source string to duplicate.
 * @return A pointer to the newly allocated string containing a duplicate of the
 *         source string, or NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       duplicated string using free().
 */
char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
