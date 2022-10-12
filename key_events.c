/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:06:54 by marolive          #+#    #+#             */
/*   Updated: 2022/10/12 12:51:04 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void     move(t_data *window, int pos_w, int pos_h)
{
    int new_w;
    int new_h;

    new_h = window->position_h;
    new_w = window->position_w;
    if (window->map[pos_w][pos_h] == '1')
        return ;
    if (window->map[pos_w][pos_h] == 'C')
        window->count_c--;
    if (window->map[pos_w][pos_h] == 'E' && window->count_c != 0)
        return ;
    if (window->map[pos_w][pos_h] == 'E')
    {
        window->finish = 1;
        ft_printf("\nYEAH !! You Win!\n");
        exit(0);
    }
    window->position_h = pos_h;
    window->position_w = pos_w;
    window->map[new_w][new_h] = '0';   
    if (!window->finish)
    {
        window->map[pos_w][pos_h] = 'P';
        ft_printf("Steps: %d\n", ++window->count_move);
    }
    render_img(window);
}

int    press_key(int keycode, t_data *window)
{
    if (keycode == KEY_UP)   //CIMA
    {
        new_img(window, PLAYER);
        move(window, window->position_w - 1, window->position_h);
    }
    if (keycode == KEY_DOWN)   //BAIXO
    {
        new_img(window, PLAYER);
        move(window, window->position_w + 1, window->position_h);
    }
    if (keycode == KEY_LEFT)   //ESQUERDA
    {   
        new_img(window, PLAYER_L);
        move(window, window->position_w, window->position_h - 1);
    }
    if (keycode == KEY_RIGHT)   //DIREITA
    {
        new_img(window, PLAYER);
        move(window, window->position_w, window->position_h + 1);
    }
    if (keycode == ESC)
        close_esc(window);
    return(0);
}

void    close_esc(t_data *window)
{
	{
		mlx_destroy_image(window->mlx, window->player);
		mlx_destroy_image(window->mlx, window->wall);
		mlx_destroy_image(window->mlx, window->colect);
		mlx_destroy_image(window->mlx, window->exit);
		mlx_destroy_image(window->mlx, window->backg);
		mlx_destroy_window(window->mlx, window->win);
		free(window->mlx);
		free_map(window->map);       //REMOVER
		exit(0);
	}
}

int close_x(t_data *window)
{
	mlx_destroy_image(window->mlx, window->player);
	mlx_destroy_image(window->mlx, window->wall);
	mlx_destroy_image(window->mlx, window->colect);
	mlx_destroy_image(window->mlx, window->exit);
	mlx_destroy_image(window->mlx, window->backg);
	free(window->mlx);
	free_map(window->map);
	exit(0);
	return(0);
}