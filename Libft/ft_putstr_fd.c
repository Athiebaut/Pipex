/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:46:50 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 14:11:44 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd - Outputs a string to the given file descriptor.
 *
 * @str: The string to output. If NULL, the function does nothing.
 * @fd: The file descriptor to which the string will be written.
 *
 * This function iterates through the given string and writes each
 * character to the specified file descriptor using the ft_putchar_fd
 * function. If the string is NULL, the function returns immediately.
 */
void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
