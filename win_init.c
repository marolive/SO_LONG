/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:54:08 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 03:30:40 by marolive         ###   ########.fr       */
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

void	len_map(t_data *window, char *path)
{
	int		fd;
	char	*s;
	int		size;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Map does not exist!\n");
	s = get_next_line(fd);
	if (!s)
		print_error("Empty line on the map!\n");
	window->col = ft_strlen(s);
	while (s)
	{
		if (s[0] == '\n')
			print_error("Empty line on the map!\n");
		size++;
		s = get_next_line(fd);
		if (s)
			free(s);
	}
	window->size_line = size;
	close(fd);
}

void	print_error(char *s)
{
	ft_printf("-- ERROR --\n");
	perror(s);
	exit (0);
}
