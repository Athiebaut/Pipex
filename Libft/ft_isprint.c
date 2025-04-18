/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:12:13 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:12:17 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isprint - Checks if a character is printable.
 *
 * @c: The character to be checked, represented as an integer.
 *
 * Description:
 * This function checks whether the given character is a printable
 * character, including space (' '). Printable characters are those
 * in the ASCII range from 32 to 126 inclusive.
 *
 * Return:
 * - 1 if the character is printable.
 * - 0 if the character is not printable.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
