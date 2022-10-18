/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:22 by marolive          #+#    #+#             */
/*   Updated: 2022/10/18 19:57:47 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	len_map(t_data *window, char *path)
{
	int		fd;
	char	*s;

	window->line = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map does not exist!\n");
		exit(0);
	}
	s = get_next_line(fd);
	window->col = ft_strlen(s);
	window->map = ft_calloc(window->size_map + 1, sizeof(char *));
	window->map[window->line] = s;
	while (s)
	{
		s = get_next_line(fd);
		window->map[++window->line] = s;
	}
	if (window->line == window->col - 1)
	{
		ft_printf("Please insert a rectangular map!!\n");
		exit(0);
	}
	free(s);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	fake_move(t_data *window, int pw, int ph)
{
	if (window->copy_map[pw][ph] == 'C' || window->copy_map[pw][ph] == '0')
	{
		if (window->copy_map[pw][ph] == 'C')
			window->count_copy_c--;
		window->copy_map[pw][ph] = 'P';
		fake_move(window, pw - 1, ph);
		fake_move(window, pw + 1, ph);
		fake_move(window, pw, ph - 1);
		fake_move(window, pw, ph + 1);
	}
}

int	copy_map(t_data *window)
{
	int	i;

	i = 0;
	window->copy_map = ft_calloc(window->size_map + 1, sizeof (char *));
	if (!window->copy_map)
		return (0);
	while (i < window->line)
	{
		window->copy_map[i] = ft_strdup(window->map[i]);
		i++;
	}
	window->copy_map[window->play_pos_w][window->play_pos_h] = '0';
	fake_move(window, window->play_pos_w, window->play_pos_h);
	free_map(window->copy_map);
	return (1);
}

void	valid_collect(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->line)
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'C')
				window->count_copy_c++;
			j++;
		}
		i++;
	}
	if (window->count_copy_c != 0)
	{
		ft_printf("No access to collectible!\n");
		exit(0);
	}
}
