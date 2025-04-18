/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:11:34 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:11:36 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalpha - Checks if a character is an alphabetic character.
 *
 * @c: The character to be checked, represented as an integer.
 *
 * This function checks whether the given character is an alphabetic
 * character (either uppercase or lowercase). It returns 1 if the character
 * is alphabetic, and 0 otherwise.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
