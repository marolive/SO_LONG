/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:26:51 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:38 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	while (dst[dlen] != '\0' && dlen < dstsize)
		dlen++;
	if (dstsize == dlen)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dlen + i < (dstsize - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (dlen + i);
}
