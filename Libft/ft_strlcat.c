/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:57 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/03 15:06:26 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tdest;
	size_t	tsrc;

	i = 0;
	tsrc = ft_strlen(src);
	if (size == 0 && !dst)
		return (tsrc);
	tdest = ft_strlen(dst);
	j = tdest;
	if (size <= tdest)
		return (size + tsrc);
	while (src[i] && i < size - tdest - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (tdest + tsrc);
}
