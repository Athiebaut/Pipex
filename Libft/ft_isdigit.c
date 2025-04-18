/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:12:01 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:12:03 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_isdigit.c
 * @brief Checks if a character is a digit.
 *
 * This function determines whether the given character (represented as an
 * integer) is a numeric digit (0-9) based on its ASCII value.
 *
 * @param c The character to check, represented as an integer.
 * @return 1 if the character is a digit (ASCII values 48 to 57), 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
