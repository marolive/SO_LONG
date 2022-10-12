/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:43 by marolive          #+#    #+#             */
/*   Updated: 2022/10/11 23:42:33 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    valid_arq(int c, char *arg)
{
    //int     len;   //VALIDAR
    char    *valid;
    
    if(c != 2)
    {
        ft_printf("Você é retardado por acaso?\n");
        exit(0);
    }
    //len = ft_strlen(arg); //VALIDAR
    if(!(valid = ft_strrchr(arg, '.'))) //AJEITAR
    {
        ft_printf("Tem que ser aquivo .ber vacilao!\n");
        exit(0);
    }
    if(ft_strncmp(valid, ".ber", 4) != 0 || ft_strlen(valid) != 4)
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
                window->count_c++;
            if(window->map[i][j] == 'E')
                window->count_e++;
            if(window->map[i][j] == 'P')
            {
                window->position_w = i;
                window->position_h = j;
                window->count_p++;
            }
            j++;
        }
        i++;
    }
}
void    valid_elements(t_data *window)
{
    count_elements(window);
    if(window->count_c < 1 || window->count_e != 1 || window->count_p != 1)
    {
        ft_printf("Assim não da né Combatente!!");
        exit(0);
    }
}

int    valid_char(t_data *window)
{
    int i;
    int j;

    i = 0;
    while(window->map[i])
    {
        j = 0;
        while(window->map[i][j])
        {
            if(!ft_strchr("10PEC\n", window->map[i][j]))
            {
                ft_printf("Mapa invalido doidão!!");
                exit(0);
            }
            j++;
        }
        i++;
    }
    return(0);
}
void    valid_wall(t_data *window)
{
    int  i;
    int  j;

    i = 0;
    while (i < window->line)
    {
        j = 0;
        while (window->map[i][j] != '\n')
        {
            if ((window->map[0][j] != '1' || window->map[window->line - 1][j] != '1') || (window->map[i][0] != '1' || window->map[i][window->col - 2] != '1'))
            {
                ft_printf("Mapa invalido doidão, se liga!!");
                exit(0);
            }
            j++;
        }
        i++;
    }
    /*i = 0;
    while (i < window->line - 1)
    {
        j = 0;
        while (window->map[i][j] != '\n')
        {
            if (window->map[i][0] != '1' || window->map[i][window->col - 2] != '1')
            {
                ft_printf("Mapa invalido doidão, se liga!!");
                exit(0);
            }
            j++;
        }
        i++;
    }*/
}
