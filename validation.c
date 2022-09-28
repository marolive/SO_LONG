/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:43 by marolive          #+#    #+#             */
/*   Updated: 2022/09/28 20:05:08 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    valid_arq(int argc, char *argv)
{
    int     len;
    char    *valid;
    
    if(argc != 2)
    {
        ft_printf("Você é retardado por acaso?\n");
        exit(0);
    }
    len = ft_strlen(argv);
    if(!(valid = ft_strrchr(argv, '.')))
    {
        ft_printf("Tem que ser aquivo .ber vacilao!\n");
        exit(0);
    }
    if(ft_strncmp(valid, ".ber", 4))
    {
        ft_printf("Tem que ser aquivo .ber vacilao!\n");
        exit(0);
    }
}

void    count_elements(t_data *window)
{
    int i;
    int j;

    i = 0;
    while(window->map[i])
    {
        j = 0;
        while(window->map[i][j])
        {
            if(window->map[i][j] == 'C')
                window->count_C++;
            if(window->map[i][j] == 'E')
                window->count_E++;
            if(window->map[i][j] == 'P')
            {
                window->position_w = i;
                window->position_h = j;
                window->count_P++;
            }
            j++;
        }
        i++;
    }
    
}
void    valid_elements(t_data *window)
{
    if(window->count_C < 1 || window->count_E != 1 || window->count_P != 1)
    {
        ft_printf("Assim não da né Combatente!!");
        exit(0);
    }
}