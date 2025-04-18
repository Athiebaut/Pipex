/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:01:07 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 13:54:26 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_striteri - Applies a function to each character of a string, passing
 *               the character's index and address to the function.
 *
 * @s: The string to iterate through. If NULL, the function does nothing.
 * @f: The function to apply to each character. It takes two arguments:
 *     - The index of the character in the string (unsigned int).
 *     - A pointer to the character itself (char*).
 *
 * Description:
 * This function iterates through the string `s` and applies the function `f`
 * to each character. The function `f` is passed the index of the character
 * and a pointer to the character itself, allowing modifications to the string
 * if needed. If the string `s` is NULL, the function exits without performing
 * any operations.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
