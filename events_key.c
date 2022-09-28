/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:06:54 by marolive          #+#    #+#             */
/*   Updated: 2022/09/28 20:30:32 by marolive         ###   ########.fr       */
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
        window->map[window->position_w -1][window->position_h] = 'P';
        mlx_destroy_image(window->mlx, window->player);
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
        render_img(window);
        
        //move(window->player, window->position_w - 1, window->position_h);
    }
    if (keycode == 1)   //BAIXO
    {
        count_elements(window);
        window->map[window->position_w][window->position_h] = '0';
        window->map[window->position_w +1][window->position_h] = 'P';
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
        window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
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
    return(0);
}
