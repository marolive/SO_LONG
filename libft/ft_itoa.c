/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:27:36 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:41:52 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbrlen(int n)
{
	int			len;
	long int	aux;

	len = 0;
	aux = n;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	aux;
	char		*mall;
	int			len;

	len = nbrlen(n);
	mall = malloc((len + 1) * sizeof(char));
	if (!mall)
		return (NULL);
	aux = 1;
	if (n < 0)
		aux = -1;
	mall[len] = '\0';
	if (n == 0)
	{
		mall[0] = '0';
		return (mall);
	}
	while (n != 0)
	{
		mall[--len] = aux * (n % 10) + 48;
		n = n / 10;
	}
	if (aux < 0)
		mall[0] = '-';
	return (mall);
}
