/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:43 by marolive          #+#    #+#             */
/*   Updated: 2022/10/18 20:08:47 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_arq(int c, char *arg)
{
	char	*valid;

	if (c != 2)
	{
		ft_printf("Wrong number of arguments!\n");
		exit(0);
	}
	valid = ft_strchr(arg, '.');
	if (!valid)
	{
		ft_printf("Only .ber files!\n");
		exit(0);
	}
	if (ft_strncmp(valid, ".ber", 4) != 0 || ft_strlen(valid) != 4)
	{
		ft_printf("Only .ber files!!\n");
		exit(0);
	}
}

void	valid_elements(t_data *window)
{
	if (window->count_c < 1 || window->count_e != 1 || window->count_p != 1)
	{
		ft_printf("Irregular number of characters!!\n");
		exit(0);
	}
}

int	valid_char(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (!ft_strchr("10PEC\n", window->map[i][j]))
			{
				ft_printf("Some invalid character on the map!!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_wall(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->line - 1)
	{
		j = 0;
		while (window->map[i][j] != '\n')
		{
			if ((window->map[0][j] != '1'
				|| window->map[window->line - 1][j] != '1')
				|| (window->map[i][0] != '1'
				|| window->map[i][window->col - 2] != '1'))
			{
				ft_printf("The map must be surrounded by a wall!!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
