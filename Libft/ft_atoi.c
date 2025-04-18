/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:13 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:18 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_atoi.c
 * @brief Implementation of the ft_atoi function, which converts a string to an integer.
 *
 * @details
 * The ft_atoi function parses the initial portion of the string pointed to by `str`
 * and converts it to an integer. It handles optional leading whitespace characters,
 * an optional '+' or '-' sign, and numeric characters. The function stops parsing
 * when a non-numeric character is encountered.
 *
 * @param str A pointer to the null-terminated string to be converted.
 * 
 * @return The integer value represented by the string, taking into account the sign.
 * If no valid conversion can be performed, the function returns 0.
 *
 * @note
 * - The function skips leading whitespace characters such as spaces, tabs, and newlines.
 * - If the string starts with a '-' sign, the resulting integer will be negative.
 * - If the string starts with a '+' sign, it is ignored.
 * - The function does not handle overflow or underflow conditions.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
