/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:55:25 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 12:55:22 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strmapi - Applies a function to each character of a string to create a 
 *              new string resulting from successive applications of the function.
 *
 * @s: The input string on which the function will be applied.
 * @f: A function that takes an unsigned int (index) and a char (character at 
 *     that index) as arguments, and returns a char (the transformed character).
 *
 * Return: A newly allocated string resulting from applying the function `f` 
 *         to each character of the input string `s`. If memory allocation fails 
 *         or if `s` is NULL, the function returns NULL.
 *
 * Note: The caller is responsible for freeing the returned string to avoid 
 *       memory leaks.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
