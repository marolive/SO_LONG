/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:40:28 by marolive          #+#    #+#             */
/*   Updated: 2022/09/24 18:03:21 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				len += ft_putchar(n - 10 + 'a');
			else
				len += ft_putchar(n - 10 + 'A');
		}
		return (len);
	}
	else
	{
		len += ft_put_hexa(n / 16, c);
		len += ft_put_hexa(n % 16, c);
	}
	return (len);
}
