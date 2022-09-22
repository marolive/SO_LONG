/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:19:42 by marolive          #+#    #+#             */
/*   Updated: 2022/09/22 05:43:53 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int put_image(t_data *window)
{
    window->wall = mlx_xpm_file_to_image(window->mlx, WALL, &window->img_width, &window->img_height);
	window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
    window->colect = mlx_xpm_file_to_image(window->mlx, COLECT, &window->img_width, &window->img_height);
    window->backg = mlx_xpm_file_to_image(window->mlx, BACKG, &window->img_width, &window->img_height);
    window->exit = mlx_xpm_file_to_image(window->mlx, EXIT, &window->img_width, &window->img_height);
    
    int i;
    int j;
    
    j = 0;
    while (j < window->line)
    {
        i = 0;
        while(window->map[j][i] != '\0')
        {
            if(window->map[j][i] == '1')
                mlx_put_image_to_window(window->mlx, window->win, window->wall, PIXEL * i, PIXEL * j);
            else if(window->map[j][i] == '0')
                mlx_put_image_to_window(window->mlx, window->win, window->backg, PIXEL * i, PIXEL * j);
            else if(window->map[j][i] == 'P')
                mlx_put_image_to_window(window->mlx, window->win, window->player, PIXEL * i, PIXEL * j);
            else if(window->map[j][i] == 'C')
                mlx_put_image_to_window(window->mlx, window->win, window->colect, PIXEL * i, PIXEL * j);
            else if(window->map[j][i] == 'E')
                mlx_put_image_to_window(window->mlx, window->win, window->exit, PIXEL * i, PIXEL * j);
            i++;
        }
        j++;
    }
    return(1);
}
