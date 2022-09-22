/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:06:38 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:06 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			(((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1]);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			i++;
		}
	}
	return (dst);
}
