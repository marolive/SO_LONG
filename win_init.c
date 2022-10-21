/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:54:08 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 05:54:00 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_data *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		free(window->mlx);
		return (0);
	}
	window->win = mlx_new_window(window->mlx, PX * (window->col - 1),
			PX * window->line, "Mini PickApple");
	if (!window->win)
	{
		free(window->win);
		return (0);
	}
	return (0);
}
