/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:56 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_calloc - Allocates memory for an array of elements and initializes it to zero.
 *
 * @nb_elem: The number of elements to allocate.
 * @size: The size of each element in bytes.
 *
 * This function allocates memory for an array of `nb_elem` elements, each of size `size`,
 * and initializes all bytes in the allocated memory to zero. It performs an overflow check
 * to ensure that the multiplication of `nb_elem` and `size` does not exceed the maximum
 * allowable size for memory allocation. If the allocation fails or the overflow check fails,
 * the function returns NULL.
 *
 * Return: A pointer to the allocated and zero-initialized memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t nb_elem, size_t size)
{
	void	*tab;

	if (nb_elem > ((sizeof(char) * 2147483424) / size))
		return (NULL);
	tab = (void *)malloc(nb_elem * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nb_elem * size));
	return (tab);
}
