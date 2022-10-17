/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:19:42 by marolive          #+#    #+#             */
/*   Updated: 2022/10/17 14:46:22 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *wd)
{
	wd->wall = mlx_xpm_file_to_image(wd->mlx, WALL, &wd->img_w, &wd->img_h);
	wd->player = mlx_xpm_file_to_image(wd->mlx, PLAYER, &wd->img_w, &wd->img_h);
	wd->colect = mlx_xpm_file_to_image(wd->mlx, COLECT, &wd->img_w, &wd->img_h);
	wd->backg = mlx_xpm_file_to_image(wd->mlx, BACKG, &wd->img_w, &wd->img_h);
	wd->exit = mlx_xpm_file_to_image(wd->mlx, EXIT, &wd->img_w, &wd->img_h);
}

void	render_img(t_data *window)
{
	int	i;
	int	j;

	j = 0;
	while (j < window->line)
	{
		i = 0;
		while (window->map[j][i])
		{
			if (window->map[j][i] == '1')
				next_img(window, window->wall, PX * i, PX * j);
			else if (window->map[j][i] == '0')
				next_img(window, window->backg, PX * i, PX * j);
			else if (window->map[j][i] == 'P')
				next_img(window, window->player, PX * i, PX * j);
			else if (window->map[j][i] == 'C')
				next_img(window, window->colect, PX * i, PX * j);
			else if (window->map[j][i] == 'E' && window->count_c != 0)
				next_img(window, window->backg, PX * i, PX * j);
			else if (window->map[j][i] == 'E' && window->count_c == 0)
				next_img(window, window->exit, PX * i, PX * j);
			i++;
		}
		j++;
	}
}

void	new_img(t_data *wd, char *img)
{
	mlx_destroy_image(wd->mlx, wd->player);
	wd->player = mlx_xpm_file_to_image(wd->mlx, img, &wd->img_w, &wd->img_h);
}

void	count_elements(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'C')
				window->count_c++;
			if (window->map[i][j] == 'E')
				window->count_e++;
			if (window->map[i][j] == 'P')
				window->count_p++;
			j++;
		}
		i++;
	}
}

void	next_img(t_data *window, char *img, int i, int j)
{
	mlx_put_image_to_window(window->mlx, window->win, img, i, j);
}
