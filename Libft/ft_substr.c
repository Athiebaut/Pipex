/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:20:55 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/04 17:17:50 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	str = (char *)malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	if (start <= slen)
		ft_strlcpy(str, s + start, len + 1);
	else
		str[0] = '\0';
	return (str);
}
