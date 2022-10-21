/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:40:57 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 06:07:59 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	fake_move(t_data *window, int pw, int ph)
{
	if (window->copy_map[pw][ph] == 'C' || window->copy_map[pw][ph] == '0')
	{
		if (window->copy_map[pw][ph] == 'C')
			window->count_copy_c--;
		window->copy_map[pw][ph] = 'P';
		fake_move(window, pw - 1, ph);
		fake_move(window, pw + 1, ph);
		fake_move(window, pw, ph - 1);
		fake_move(window, pw, ph + 1);
	}
}

int	copy_map(t_data *window)
{
	int	i;

	i = 0;
	window->copy_map = ft_calloc(window->size_line + 1, sizeof (char *));
	if (!window->copy_map)
	{
		free_map(window->copy_map);
		return (0);
	}
	while (i < window->line)
	{
		window->copy_map[i] = ft_strdup(window->map[i]);
		i++;
	}
	window->copy_map[window->play_pos_w][window->play_pos_h] = '0';
	fake_move(window, window->play_pos_w, window->play_pos_h);
	return (1);
}

void	valid_collect(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->line)
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'C')
				window->count_copy_c++;
			j++;
		}
		i++;
	}
	if (window->count_copy_c != 0)
		print_error("No access to any collectible!\n");
}

void	valid_exit(t_data *window)
{
	if (window->copy_map[window->pos_exit_w - 1][window->pos_exit_h] != 'P'
		&& window->copy_map[window->pos_exit_w + 1][window->pos_exit_h] != 'P'
		&& window->copy_map[window->pos_exit_w][window->pos_exit_h - 1] != 'P'
		&& window->copy_map[window->pos_exit_w][window->pos_exit_h + 1] != 'P')
		print_error("Map without exit!!\n");
}
