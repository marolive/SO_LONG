/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:06:54 by marolive          #+#    #+#             */
/*   Updated: 2022/10/18 19:54:30 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *window, int pos_w, int pos_h)
{
	int	new_w;
	int	new_h;

	new_h = window->play_pos_h;
	new_w = window->play_pos_w;
	if (window->map[pos_w][pos_h] == '1')
		return ;
	if (window->map[pos_w][pos_h] == 'C')
		window->count_c--;
	if (window->map[pos_w][pos_h] == 'E' && window->count_c != 0)
		return ;
	if (window->map[pos_w][pos_h] == 'E')
	{
		window->finish = 1;
		print_winner(window);
	}
	window->play_pos_h = pos_h;
	window->play_pos_w = pos_w;
	window->map[new_w][new_h] = '0';
	if (!window->finish)
	{
		window->map[pos_w][pos_h] = 'P';
		ft_printf("Steps: %d\n", ++window->count_move);
	}
	render_img(window);
}

int	press_key(int keycode, t_data *window)
{
	if (keycode == KEY_UP)
	{
		new_img(window, PLAYER);
		move(window, window->play_pos_w - 1, window->play_pos_h);
	}
	if (keycode == KEY_DOWN)
	{
		new_img(window, PLAYER);
		move(window, window->play_pos_w + 1, window->play_pos_h);
	}
	if (keycode == KEY_LEFT)
	{
		new_img(window, PLAYER_L);
		move(window, window->play_pos_w, window->play_pos_h - 1);
	}
	if (keycode == KEY_RIGHT)
	{
		new_img(window, PLAYER);
		move(window, window->play_pos_w, window->play_pos_h + 1);
	}
	if (keycode == ESC)
		close_esc(window);
	return (0);
}

void	print_winner(t_data *window)
{
	ft_printf("\nYEAH !! You Winner!\n\n");
	mlx_destroy_image(window->mlx, window->player);
	mlx_destroy_image(window->mlx, window->wall);
	mlx_destroy_image(window->mlx, window->colect);
	mlx_destroy_image(window->mlx, window->exit);
	mlx_destroy_image(window->mlx, window->backg);
	mlx_destroy_window(window->mlx, window->win);
	free(window->mlx);
	free_map(window->map);
	exit(0);
}

void	close_esc(t_data *window)
{
	mlx_destroy_image(window->mlx, window->player);
	mlx_destroy_image(window->mlx, window->wall);
	mlx_destroy_image(window->mlx, window->colect);
	mlx_destroy_image(window->mlx, window->exit);
	mlx_destroy_image(window->mlx, window->backg);
	mlx_destroy_window(window->mlx, window->win);
	free(window->mlx);
	free_map(window->map);
	exit(0);
}

int	close_x(t_data *window)
{
	mlx_destroy_image(window->mlx, window->player);
	mlx_destroy_image(window->mlx, window->wall);
	mlx_destroy_image(window->mlx, window->colect);
	mlx_destroy_image(window->mlx, window->exit);
	mlx_destroy_image(window->mlx, window->backg);
	free(window->mlx);
	free_map(window->map);
	exit(0);
	return (0);
}
