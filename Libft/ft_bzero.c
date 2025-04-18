/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:43 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:46 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - Sets the first n bytes of the memory area pointed to by s to zero.
 * 
 * @s: Pointer to the memory area to be zeroed.
 * @n: Number of bytes to set to zero.
 * 
 * This function writes n zero bytes to the memory area pointed to by s.
 * If n is zero, the function does nothing.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
