/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:15:51 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/05 14:22:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putendl_fd - Outputs a string to the given file descriptor, followed by a newline.
 * 
 * @s: The string to output. If NULL, the function does nothing.
 * @fd: The file descriptor to write to.
 * 
 * This function writes the string `s` to the file descriptor `fd` using
 * the `ft_putstr_fd` function, and then writes a newline character ('\n').
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
