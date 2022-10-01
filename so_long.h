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
}			t_data;

int 	len_map(t_data *window, char *path);
void	free_map(char **map);
void	put_image(t_data *window);
int		render_img(t_data *window);
void    valid_arq(int argc, char *argv);
void    count_elements(t_data *window);
void    valid_elements(t_data *window);
int   	init_window(t_data *window);
int		movements(int keycode, t_data *window);
int		close_x(t_data *window);

#endif