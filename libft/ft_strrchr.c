/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:41:46 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:54 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		if (i == 0)
			return (0);
		i--;
	}
}
