/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:54:08 by marolive          #+#    #+#             */
/*   Updated: 2022/10/17 14:01:37 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_data *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (0);
	window->win = mlx_new_window(window->mlx, PX * (window->col - 1),
			PX * window->line, "Mini PickApple");
	if (window->win == NULL)
	{
		free(window->win);
		return (0);
	}
	return (0);
}

int	render_map(t_data *window, char *path)
{
	int		fd;
	char	*s;
	int		size;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Mapa não existe!\n");
		exit(0);
	}
	s = get_next_line(fd);
	window->col = ft_strlen(s);
	while (s)
	{
		s = get_next_line(fd);
		size++;
	}
	window->size_map = size;
	return (1);
}
