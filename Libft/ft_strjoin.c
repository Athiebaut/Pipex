/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:26:34 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 13:14:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/**
 * ft_strjoin - Concatenates two strings into a newly allocated string.
 *
 * @s1: The first string to concatenate.
 * @s2: The second string to concatenate.
 *
 * This function allocates memory for a new string that is the result of
 * concatenating the strings `s1` and `s2`. If either `s1` or `s2` is NULL,
 * the function returns NULL. If memory allocation fails, the function also
 * returns NULL.
 *
 * Return: A pointer to the newly allocated string containing the concatenated
 *         result of `s1` and `s2`, or NULL if an error occurs.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(char)) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
