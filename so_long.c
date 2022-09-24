/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:23 by marolive          #+#    #+#             */
/*   Updated: 2022/09/24 18:06:04 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	window;
	
	if(argc != 2)
	{
		ft_printf("Algo errado... O que você quer afinal?\n");
		return(1);
	}
	window.mlx = mlx_init();
	if(window.mlx == NULL)
		return(1);
	len_map(&window, argv[1]);
	window.win = mlx_new_window(window.mlx, PIXEL * (window.col - 1), PIXEL * window.line, "Mini PickApple");
	if(window.win == NULL)
	{
		free(window.win);
		return(1);
	}
	put_image(&window);	
	mlx_key_hook(window.win, close_esc, &window);
	mlx_hook(window.win, 17, 0, close_x, &window);
	mlx_loop(window.mlx);
	close_map(&window);
	//mlx_destroy_window(window.mlx, window.win);
	//free(window.mlx);
}