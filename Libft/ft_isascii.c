/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:11:48 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:11:50 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isascii - Checks if a given character is part of the ASCII character set.
 *
 * @c: The character to be checked, represented as an integer.
 *
 * Return: 
 *   - 1 if the character is within the ASCII range (0 to 127).
 *   - 0 otherwise.
 *
 * Description:
 * This function determines whether the input integer corresponds to a valid
 * ASCII character. The ASCII character set includes values from 0 to 127.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
