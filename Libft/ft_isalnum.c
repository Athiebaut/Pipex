/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:11:11 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:11:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalnum - Checks if the given character is alphanumeric.
 *
 * @c: The character to be checked, represented as an integer.
 *
 * This function checks whether the input character is either a letter
 * (uppercase or lowercase) or a digit. It returns 1 if the character
 * is alphanumeric, and 0 otherwise.
 *
 * Return: 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}
