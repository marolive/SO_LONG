/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:23:36 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:50 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0 || s1[i] == '\0')
			return (diff);
		i++;
	}
	return (0);
}
