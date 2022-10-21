/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:52:41 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 18:36:26 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_char(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->line)
	{
		j = 0;
		while (window->map[i][j])
		{
			if (!ft_strchr("10PEC\n", window->map[i][j]))
				print_error("Some invalid character on the map!!\n");
			j++;
		}
		i++;
	}
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
				print_error("The map must be surrounded by a wall!!\n");
			j++;
		}
		i++;
	}
}

void	valid_square(t_data *window)
{
	if (window->line == window->col - 1)
		print_error("Please insert a rectangular map!!\n");
}
