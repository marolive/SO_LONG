/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:36:28 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:52 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0 || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& (i + j) < n && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
