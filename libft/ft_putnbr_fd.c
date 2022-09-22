/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:21:53 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:42:23 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_magnitude(int n)
{
	int	mag;

	mag = 1;
	if (n < 0)
		mag = -1;
	while (1)
	{
		n /= 10;
		if (n == 0)
			return (mag);
		mag *= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	j;
	int	mag;

	mag = get_magnitude(n);
	if (n < 0)
		ft_putchar_fd ('-', fd);
	while (1)
	{
		j = n / mag + '0';
		ft_putchar_fd(j, fd);
		n %= mag;
		mag /= 10;
		if (mag == 0)
			break ;
	}
}
