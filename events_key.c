/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:06:54 by marolive          #+#    #+#             */
/*   Updated: 2022/10/01 20:42:56 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int     move(t_data *window, int pos_w, int pos_h)
{
    int new_w;
    int new_h;

    new_h = window->position_h;
    new_w = window->position_w;
    if(window->map[pos_w][pos_h] == '0')
    {
        
    }
}*/

int    movements(int keycode, t_data *window)
{
    if (keycode == 13)   //CIMA
    {
        count_elements(window);
        window->map[window->position_w][window->position_h] = '0';
        window->map[window->position_w - 1][window->position_h] = 'P';
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        render_img(window);
        
        //move(window->player, window->position_w - 1, window->position_h);
    }
    if (keycode == 1)   //BAIXO
    {
        count_elements(window);
        window->map[window->position_w][window->position_h] = '0';
        window->map[window->position_w + 1][window->position_h] = 'P';
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        render_img(window);
        //move(window->player, window->position_w + 1, window->position_h);
    }
    if (keycode == 0)   //ESQUERDA
    {   
        count_elements(window);
        window->map[window->position_w][window->position_h] = '0';
        window->map[window->position_w][window->position_h -1] = 'P';
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER_L, &window->img_width, &window->img_height);
        render_img(window);
        //move(window->player, window->position_w, window->position_h - 1);
    }
    if (keycode == 2)   //DIREITA
    {
        count_elements(window);
        window->map[window->position_w][window->position_h] = '0';
        window->map[window->position_w][window->position_h +1] = 'P';
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        render_img(window);
        //move(window->player, window->position_w, window->position_h + 1);
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