NAME    = so_long
SRCS    = so_long.c \
			map.c \
			put_img.c \
			close_win.c
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
OBJS    = $(SRCS:.c=.o)
CC	    = cc
RM	    = rm -f
CFLAGS  = -Wall -Werror -Wextra
LIB_DIR = libft
LIB_A = $(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIB_A)
	$(CC) $^ -L $(MLX_DIR) -l $(MLX_DIR) -framework OpenGL -framework AppKit -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $(<:.c=.o)

$(MLX_LIB):
	make all -C $(MLX_DIR)

$(LIB_A):
	make all -C $(LIB_DIR)

clean:
	$(RM) $(OBJS) $(NAME)
	make clean -C $(MLX_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(LIB_A)

re: fclean all

.PHONY: all clean fclean re
