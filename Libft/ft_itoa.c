/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:35:37 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 19:11:05 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an unsigned integer to a string representation.
 *
 * This helper function populates the string `str` with the digits of the unsigned integer `nb`,
 * starting from the least significant digit and working backwards.
 *
 * @param str The string buffer to populate with the number's digits.
 * @param nb The unsigned integer to convert.
 * @param size The index in the string buffer where the conversion should start.
 * @return A pointer to the populated string buffer.
 */
static char	*ft_char(char *str, unsigned int nb, long int size)
{
	while (nb > 0)
	{
		str[size] = 48 + (nb % 10);
		nb = nb / 10;
		size--;
	}
	return (str);
}

/**
 * @brief Calculates the number of characters needed to represent an integer as a string.
 *
 * This helper function determines the size of the string required to represent the integer `nb`,
 * including space for a negative sign if applicable and the null terminator.
 *
 * @param nb The integer whose string size is to be calculated.
 * @return The size of the string required to represent the integer.
 */
static long int	str_size(int nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size = 1;
	while (nb != 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * The ft_itoa function converts the integer `n` to its string representation and returns a pointer
 * to the newly allocated string. The caller is responsible for freeing the allocated memory.
 *
 * @param n The integer to convert.
 * @return A pointer to the string representation of the integer, or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char			*str;
	long int		size;
	unsigned int	nb;

	size = str_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size = size - 1;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nb = n * -1;
		str[0] = '-';
	}
	else
		nb = n;
	str = ft_char(str, nb, size);
	return (str);
}
