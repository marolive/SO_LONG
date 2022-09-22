/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:27:42 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:57 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mall;
	size_t	i;
	size_t	fim;
	size_t	st;

	if (!s1)
		return (NULL);
	st = 0;
	while (s1[st] && ft_strchr(set, s1[st]))
		st++;
	fim = ft_strlen(s1);
	while (fim > st && ft_strchr(set, s1[fim - 1]))
		fim--;
	mall = (char *)malloc(sizeof(*s1) * (fim - st + 1));
	if (!mall)
		return (NULL);
	i = 0;
	while (st < fim)
		mall[i++] = s1[st++];
	mall[i] = '\0';
	return (mall);
}
