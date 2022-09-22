/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:56:39 by marolive          #+#    #+#             */
/*   Updated: 2022/09/21 23:32:15 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_esc(int keycode, t_data *window)
{
	if (keycode == 53)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}
int close_x(void)
{
	exit(0);
	return(0);
}