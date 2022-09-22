/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:16:22 by marolive          #+#    #+#             */
/*   Updated: 2022/09/22 05:41:38 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  len_map(t_data *window)
{
    int fd;
    char *s;

    window->line = 0;
    fd = open("map/map1.ber", O_RDONLY);
    if(fd < -1)
        return(0);
    s = get_next_line(fd);
    window->col = ft_strlen(s);
    window->map = ft_calloc(window->col, sizeof(char *));
    window->map[window->line] = s;
    while(s)
    {
        printf("%s", window->map[window->line]); // REMOVER
        s = get_next_line(fd);
        window->map[++window->line] = s;
    }
    return(1);
}
