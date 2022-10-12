/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:43 by marolive          #+#    #+#             */
/*   Updated: 2022/10/12 19:12:42 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    valid_arq(int c, char *arg)
{
    char    *valid;
    //char    *len;
    
    //len = ft_strlen(arg);
    if(c != 2)
    {
        ft_printf("Você é retardado por acaso?\n");
        exit(0);
    }
   // if (len - 4 == NULL)
    valid = ft_strchr(arg, '.');
    if(!valid)
    {
        ft_printf("Tem que ser aquivo .ber vacilao!\n");
        exit(0);
    }
    if(ft_strncmp(valid, ".ber", 4) != 0 || ft_strlen(valid) != 4)
    {
        ft_printf("Ja falei que é aquivo .ber vacilao!\n");
        exit(0);
    }
}

void    valid_elements(t_data *window)
{
    count_elements(window);
    if(window->count_c < 1 || window->count_e != 1 || window->count_p != 1)
    {
        ft_printf("Assim não da né Combatente!!\n");
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
                ft_printf("Mapa invalido doidão!!\n");
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
    while (i < window->line - 1)
    {
        j = 0;
        while (window->map[i][j] != '\n')
        {
            if ((window->map[0][j] != '1' || window->map[window->line - 1][j] != '1') || (window->map[i][0] != '1' || window->map[i][window->col - 2] != '1'))
            {
                ft_printf("Mapa invalido doidão, se liga!!\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void    valid_exit(char **copy_map, int pw, int ph)
{
    t_data  window;
    //char    **copy_map;
    //copy_map = window.map;
    int     i;
        
    i = 0;
    while(i < window.line)
    {
        ft_printf("%s", copy_map[i]);
        i++;
    }
    /*if (copy_map[pw][ph] == '1')
        return ;
    if (copy_map[pw][ph] == 'C')
        window.count_C--;
    if (copy_map[pw][ph] == 'E')
        window.count_e++;
    //copy_map[pw][ph] = 'P';
    valid_exit(copy_map, pw - 1, ph);
    valid_exit(copy_map, pw + 1, ph);
    valid_exit(copy_map, pw, ph - 1);
    valid_exit(copy_map, pw, ph + 1);
    if (window.count_C != 0)
    {
        ft_printf("Tá errado esse mapa ai!\n");
        exit(0);
    }*/
}