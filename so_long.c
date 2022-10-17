/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:23 by marolive          #+#    #+#             */
/*   Updated: 2022/10/15 07:51:51 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	window;

	valid_arq(argc, argv[1]);
	render_map(&window, argv[1]);
	len_map(&window, argv[1]);
	valid_elements(&window);
	copy_elements(&window);
	valid_wall(&window);
	valid_char(&window);
	copy_map(&window);
	valid_collect(&window);
	valid_exit(&window);
	init_window(&window);
	put_image(&window);
	render_img(&window);
	mlx_key_hook(window.win, press_key, &window);
	mlx_hook(window.win, 17, 0, close_x, &window);
	mlx_loop(window.mlx);
}
