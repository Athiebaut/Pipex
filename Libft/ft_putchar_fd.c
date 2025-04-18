/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:24:55 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 14:11:35 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putchar_fd.c
 * @brief Outputs a character to the given file descriptor.
 *
 * This function writes the character 'c' to the file descriptor specified
 * by 'fd'. It is commonly used to output characters to standard output,
 * standard error, or a file.
 *
 * @param c The character to output.
 * @param fd The file descriptor to which the character will be written.
 *           Common values are:
 *           - 1 for standard output (stdout)
 *           - 2 for standard error (stderr)
 *
 * @note The function does not handle errors that may occur during the write
 *       operation. It is the caller's responsibility to ensure that the file
 *       descriptor is valid.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
