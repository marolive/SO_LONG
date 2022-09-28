/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:56:39 by marolive          #+#    #+#             */
/*   Updated: 2022/09/26 19:22:50 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_esc(int keycode, t_data *window)
{
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
	return (0);
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


/*int	close_map(t_data *window)
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
	return(0);
}*/