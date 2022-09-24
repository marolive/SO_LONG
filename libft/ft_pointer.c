/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:51:31 by marolive          #+#    #+#             */
/*   Updated: 2022/09/24 18:03:03 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(unsigned long n, char c)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(48 + n);
		else
			len += ft_putchar(n - 10 + 'a');
	}
	else
	{
		len += ft_pointer(n / 16, c);
		len += ft_pointer(n % 16, c);
	}
	return (len);
}
