/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 05:57:32 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 05:51:30 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_value(t_data *window)
{
	window->col = 0;
	window->line = 0;
	window->img_h = 0;
	window->img_w = 0;
	window->position_w = 0;
	window->position_h = 0;
	window->play_pos_w = 0;
	window->play_pos_h = 0;
	window->pos_exit_w = 0;
	window->pos_exit_h = 0;
	window->size_line = 0;
	window->count_c = 0;
	window->count_e = 0;
	window->count_p = 0;
	window->count_copy_c = 0;
	window->count_move = 0;
	window->finish = 0;
}

void	print_error(char *s)
{
	ft_printf("-- ERROR --\n");
	perror(s);
	exit (0);
}
