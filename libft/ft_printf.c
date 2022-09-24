/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:54 by marolive          #+#    #+#             */
/*   Updated: 2022/09/24 18:09:21 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_arg(char c, va_list ar)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ar, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ar, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ar, int)));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(ar, unsigned int)));
	if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			return (ft_put_hexa(va_arg(ar, unsigned int), c));
		else
			return (ft_put_hexa(va_arg(ar, unsigned int), c));
	}
	if (c == 'p')
		return (ft_putstr("0x") + ft_pointer(va_arg(ar, unsigned long), c));
	if (c == '%')
		return (ft_putchar(c));
	else
		return (0);
}

int	ft_printf(const char *st, ...)
{
	va_list	ar;
	int		i;
	int		j;

	va_start(ar, st);
	i = 0;
	j = 0;
	while (st[i])
	{
		if (st[i] == '%')
		{
			j += ft_printf_arg(st[i + 1], ar);
			i++;
		}
		else
			j += ft_putchar(st[i]);
		i++;
	}
	va_end(ar);
	return (j);
}
