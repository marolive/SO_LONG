/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:06:54 by marolive          #+#    #+#             */
/*   Updated: 2022/10/07 20:54:28 by marolive         ###   ########.fr       */
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
        ft_printf("\nYEAH !! You Win!\nPress ESC or click in X button!\n");
    }
    window->position_h = pos_h;
    window->position_w = pos_w;
    window->map[new_w][new_h] = '0';   
    if(!window->finish)
    {
        window->map[pos_w][pos_h] = 'P';
        ft_printf("Steps: %d\n", ++window->count_move);
    }
    render_img(window);
}

int    press_key(int keycode, t_data *window)
{
    if (keycode == 13)   //CIMA
    {
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        move(window, window->position_w - 1, window->position_h);
    }
    if (keycode == 1)   //BAIXO
    {
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        move(window, window->position_w + 1, window->position_h);
    }
    if (keycode == 0)   //ESQUERDA
    {   
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER_L, &window->img_width, &window->img_height);
        move(window, window->position_w, window->position_h - 1);
    }
    if (keycode == 2)   //DIREITA
    {
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        move(window, window->position_w, window->position_h + 1);
    }
    if (keycode == 53)
	{
		mlx_destroy_image(window->mlx, window->player);
		mlx_destroy_image(window->mlx, window->wall);
		mlx_destroy_image(window->mlx, window->colect);
		mlx_destroy_image(window->mlx, window->exit);
		mlx_destroy_image(window->mlx, window->backg);
		mlx_destroy_window(window->mlx, window->win);
		ft_printf("Keypress: %d\n", keycode); 
		free(window->mlx);
		free_map(window->map);       //REMOVER
		exit(0);
	}
    return(0);
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