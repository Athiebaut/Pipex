/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:46:41 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:25:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_tolower - Converts an uppercase letter to its lowercase equivalent.
 *
 * @c: The character to be converted.
 *
 * Description:
 * This function checks if the input character is an uppercase letter
 * (between 'A' and 'Z'). If it is, the function converts it to its
 * corresponding lowercase letter by adding 32 to its ASCII value.
 * If the character is not an uppercase letter, it is returned unchanged.
 *
 * Return:
 * The lowercase equivalent of the input character if it is an uppercase
 * letter; otherwise, the input character is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
