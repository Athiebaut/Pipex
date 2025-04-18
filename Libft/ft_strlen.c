/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:14:13 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:14:15 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_strlen.c
 * @brief Implementation of the ft_strlen function.
 *
 * This function calculates the length of a null-terminated string.
 *
 * @param str A pointer to the null-terminated string whose length is to be calculated.
 * @return The length of the string (number of characters before the null terminator).
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
