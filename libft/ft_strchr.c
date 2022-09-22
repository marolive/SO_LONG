/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:22:29 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:30 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0' && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return (str);
	return (0);
}
