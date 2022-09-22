/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:23 by marolive          #+#    #+#             */
/*   Updated: 2022/09/22 05:44:11 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	window;
	
	window.mlx = mlx_init();
	len_map(&window);
	window.win = mlx_new_window(window.mlx, PIXEL * (window.col - 1), PIXEL * window.line, "Mini PickApple");
	put_image(&window);	
	mlx_key_hook(window.win, close_esc, &window);
	mlx_hook(window.win, 17, 0, close_x, &window);
	mlx_loop(window.mlx);
}