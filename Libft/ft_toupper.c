/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:40:19 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/02 16:59:30 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_toupper.c
 * @brief Converts a lowercase letter to its uppercase equivalent.
 *
 * This function checks if the given character is a lowercase letter
 * (between 'a' and 'z'). If it is, the function converts it to the
 * corresponding uppercase letter by subtracting 32 from its ASCII value.
 * If the character is not a lowercase letter, it is returned unchanged.
 *
 * @param c The character to be converted.
 * @return The uppercase equivalent of the character if it is a lowercase
 *         letter; otherwise, the character itself.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
