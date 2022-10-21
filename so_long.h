/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:38:45 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 03:48:55 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WALL "img/wall.xpm"
# define PLAYER "img/player.xpm"
# define PLAYER_L "img/player_l.xpm"
# define COLECT "img/colect.xpm"
# define BACKG "img/backg.xpm"
# define EXIT "img/exit.xpm"
# define PX 64

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define ESC 53

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*wall;
	char	*player;
	char	*colect;
	char	*backg;
	char	*exit;
	int		col;
	int		line;
	char	**map;
	char	**copy_map;
	int		img_w;
	int		img_h;
	int		position_w;
	int		position_h;
	int		play_pos_w;
	int		play_pos_h;
	int		pos_exit_w;
	int		pos_exit_h;
	int		count_c;
	int		count_e;
	int		count_p;
	int		count_copy_c;
	int		count_move;
	int		finish;
	int		size_line;
}			t_data;

void	initial_value(t_data *window);
void	move(t_data *window, int pos_w, int pos_h);
int		press_key(int keycode, t_data *window);
void	print_winner(t_data *window);
void	close_esc(t_data *window);
int		close_x(t_data *window);
void	copy_elements(t_data *window);
void	fake_move(t_data *window, int pw, int ph);
int		copy_map(t_data *window);
void	valid_collect(t_data *window);
void	valid_exit(t_data *window);
void	render_map(t_data *window, char *path);
void	free_map(char **map);
void	put_image(t_data *window);
void	next_img(t_data *window, char *img, int i, int j);
void	render_img(t_data *window);
void	count_elements(t_data *window);
void	new_img(t_data *window, char *img);
void	valid_arq(int c, char *arg);
void	valid_char(t_data *window);
void	valid_wall(t_data *window);
void	valid_square(t_data *window);
int		init_window(t_data *window);
void	len_map(t_data *window, char *path);
void	print_error(char *s);

#endif
