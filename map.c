/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:22 by marolive          #+#    #+#             */
/*   Updated: 2022/10/13 18:42:13 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  len_map(t_data *window, char *path)
{
    int     fd;
    char    *s;
    int     size;

    size = 0;
    window->line = 0;
    fd = open(path, O_RDONLY);
    if(fd < -1)
        return(0);
    s = get_next_line(fd);
    window->col = ft_strlen(s);
    window->map = ft_calloc(window->col, sizeof(char *));
    window->map[window->line] = s;
    while(s)
    {
        //ft_printf("%s", window->map[window->line]); // REMOVER
        s = get_next_line(fd);
        window->map[++window->line] = s;
    }
    size = window->line;
    if(size == window->col - 1)
    {
        ft_printf("Mapa quadrado igual a você!!\n");
        exit(0);
    }
    return(1);
}

void    free_map(char **map)
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