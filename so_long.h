#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

#define WALL "img/wall.xpm"
#define PLAYER "img/player.xpm"
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
	int		count_C;
	int		count_E;
	int		count_P;
}			t_data;

int		close_esc(int keycode, t_data *window);
int		close_x(t_data *window);
int 	len_map(t_data *window, char *path);
void	put_image(t_data *window);
void	free_map(char **map);
int		close_map(t_data *window);
void    valid_arq(int argc, char *argv);
int   	init_window(t_data *window);
void    count_elements(t_data *window);
int		movements(int keycode, t_data *window);
int		render_img(t_data *window);

#endif