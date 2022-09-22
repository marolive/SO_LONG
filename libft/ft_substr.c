/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:56:44 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:59 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*a;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (len > ft_strlen(s))
		a = (char *)malloc(ft_strlen(s) + 1);
	else
		a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start & j < len)
			a[j++] = s[i];
		i++;
	}
	a[j] = '\0';
	return (a);
}
