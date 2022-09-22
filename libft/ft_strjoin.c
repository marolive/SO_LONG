/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:48:37 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:36 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count;

	if (!s1 || !s2)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	a = malloc(count + 1);
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	ft_strlcpy(a + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (a);
}
