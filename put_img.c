/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:19:42 by marolive          #+#    #+#             */
/*   Updated: 2022/10/12 16:25:09 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image(t_data *window)
{
    window->wall = mlx_xpm_file_to_image(window->mlx, WALL, &window->img_width, &window->img_height);
	window->player = mlx_xpm_file_to_image(window->mlx, PLAYER, &window->img_width, &window->img_height);
    window->colect = mlx_xpm_file_to_image(window->mlx, COLECT, &window->img_width, &window->img_height);
    window->backg = mlx_xpm_file_to_image(window->mlx, BACKG, &window->img_width, &window->img_height);
    window->exit = mlx_xpm_file_to_image(window->mlx, EXIT, &window->img_width, &window->img_height);
}
 
int render_img(t_data *window)
 {   
    int i;
    int j;
    
    j = 0;
    while (j < window->line)
    {
        i = 0;
        while(window->map[j][i])
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
            {
                if(window->count_c != 0)
                    mlx_put_image_to_window(window->mlx, window->win, window->backg, PIXEL * i, PIXEL * j);
                if(window->count_c == 0)
                    mlx_put_image_to_window(window->mlx, window->win, window->exit, PIXEL * i, PIXEL * j);
            }
            i++;
        }
        j++;
    }
    return(0);
}

void new_img(t_data *window, char *img)
{
    mlx_destroy_image(window->mlx, window->player);
    window->player = mlx_xpm_file_to_image(window->mlx, img, &window->img_width, &window->img_height);
}

void    count_elements(t_data *window)
{
    int i;
    int j;

    i = 0;
    while(window->map[i])
    {
        j = 0;
        while(window->map[i][j])
        {
            if(window->map[i][j] == 'C')
                window->count_c++;
            if(window->map[i][j] == 'E')
                window->count_e++;
            if(window->map[i][j] == 'P')
            {
                window->position_w = i;
                window->position_h = j;
                window->count_p++;
            }
            j++;
        }
        i++;
    }
}