/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:23 by marolive          #+#    #+#             */
/*   Updated: 2022/10/01 16:52:29 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	window;
	
	valid_arq(argc, argv[1]);
	len_map(&window, argv[1]);
	valid_elements(&window);
	init_window(&window);
	put_image(&window);
	render_img(&window);	
	mlx_key_hook(window.win, movements, &window);
	//mlx_key_hook(window.win, close_esc, &window);
	mlx_hook(window.win, 17, 0, close_x, &window);
	mlx_loop(window.mlx);
	//close_map(&window);
}