/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:22 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 18:54:13 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free(s);
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

void	render_map(t_data *window, char *path)
{
	int		fd;
	char	*s;

	window->line = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Map does not exist!\n");
	s = get_next_line(fd);
	if (!s)
		print_error("Empty line on the map!\n");
	window->col = ft_strlen(s);
	window->map = ft_calloc(window->size_line + 1, sizeof(char *));
	if (!window->map)
		print_error("Map Null\n");
	window->map[window->line] = s;
	while (s)
	{
		s = get_next_line(fd);
		window->map[++window->line] = s;
	}
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
