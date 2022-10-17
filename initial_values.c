/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 05:57:32 by marolive          #+#    #+#             */
/*   Updated: 2022/10/15 07:51:31 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_value(t_data *window)
{
	window->count_c = 0;
	window->count_e = 0;
	window->count_p = 0;
	window->count_copy_c = 0;
	window->count_move = 0;
	window->finish = 0;
}

void	copy_elements(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->line)
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'E')
			{
				window->pos_exit_w = i;
				window->pos_exit_h = j;
			}
			if (window->map[i][j] == 'P')
			{
				window->play_pos_w = i;
				window->play_pos_h = j;
			}
			j++;
		}
		i++;
	}
}

void	valid_exit(t_data *window)
{
	if (window->copy_map[window->pos_exit_w - 1][window->pos_exit_h] != 'P'
		&& window->copy_map[window->pos_exit_w + 1][window->pos_exit_h] != 'P'
		&& window->copy_map[window->pos_exit_w][window->pos_exit_h - 1] != 'P'
		&& window->copy_map[window->pos_exit_w][window->pos_exit_h + 1] != 'P')
	{
		ft_printf("Mapa sem saida Zé mané, se liga!!\n");
		exit(0);
	}
}
