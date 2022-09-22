#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>  //REMOVER

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
}			t_data;

int	close_esc(int keycode, t_data *window);
int	close_x(void);
int len_map(t_data *window);
int	put_image(t_data *window);

#endif