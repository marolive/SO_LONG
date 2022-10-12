#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

#define WALL "img/wall.xpm"
#define PLAYER "img/player.xpm"
#define PLAYER_L "img/player_l.xpm"
#define	COLECT "img/colect.xpm"
#define	BACKG "img/backg.xpm"
#define EXIT "img/exit.xpm"
#define PIXEL 64

#define KEY_UP 13
#define KEY_DOWN 1
#define KEY_LEFT 0
#define KEY_RIGHT 2
#define ESC 53

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
	int		img_width;
	int		img_height;
	int 	position_w;
	int		position_h;
	int		count_c;
	int		count_e;
	int		count_p;
	int		count_move;
	int		finish;
}			t_data;

int 	len_map(t_data *window, char *path);
void	free_map(char **map);
void	put_image(t_data *window);
int		render_img(t_data *window);
void    valid_arq(int c, char *arg);
void    count_elements(t_data *window);
void    valid_elements(t_data *window);
int		valid_char(t_data *window);
int   	init_window(t_data *window);
void    move(t_data *window, int pos_w, int pos_h);
int		press_key(int keycode, t_data *window);
int		close_x(t_data *window);
void    valid_wall(t_data *window);
void	new_img(t_data *window, char *img);
void    close_esc(t_data *window);
void    valid_exit(char **copy_map, int pw, int ph);

#endif