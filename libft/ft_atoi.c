/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:48:45 by marolive          #+#    #+#             */
/*   Updated: 2022/06/24 15:41:36 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long			resul;
	unsigned int	i;
	long			neg;

	neg = 1;
	resul = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resul = resul * 10 + str[i] - '0';
		i++;
	}
	return ((int)resul * neg);
}
