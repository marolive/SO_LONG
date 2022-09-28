/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:22 by marolive          #+#    #+#             */
/*   Updated: 2022/09/28 14:36:48 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  len_map(t_data *window, char *path)
{
    int fd;
    char *s;

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
        ft_printf("%s", window->map[window->line]); // REMOVER
        s = get_next_line(fd);
        window->map[++window->line] = s;
    }
    return(1);
}
/*
int v_map(t_data *window)
{
    if(window->map == .ber)     !CHECK!
    if(window->map != "10PCE")  !CHECK!
    if(window->map == 0)        !CHECK!   
    if(window->map = (w == h))
    if(window->map != 'C' == NULL) 
    
}*/

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