/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:40:35 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 14:14:31 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putnbr_fd.c
 * @brief Outputs an integer to the given file descriptor.
 *
 * This function takes an integer and a file descriptor as input and writes
 * the integer to the specified file descriptor. It handles negative numbers
 * by outputting a '-' sign and converting the number to its absolute value
 * before processing. The function uses recursion to handle multi-digit numbers.
 *
 * @param nb The integer to output.
 * @param fd The file descriptor to write to.
 *
 * @note This function relies on the helper function `ft_putchar_fd` to write
 *       individual characters to the file descriptor.
 */
void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		n = -nb;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
}
