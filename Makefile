NAME    = so_long
SRCS    = so_long.c \
			map.c \
			put_img.c \
			validation.c \
			win_init.c \
			key_events.c
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a
OBJS    = $(SRCS:.c=.o)
CC	    = cc
RM	    = rm -f
CFLAGS  = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJS) $(MLX) $(LIB)
	$(CC) $^ -L $(MLX_DIR) -l $(MLX_DIR) -framework OpenGL -framework AppKit -g -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $(<:.c=.o)

$(MLX):
	make all -C $(MLX_DIR)

$(LIB):
	make all -C $(LIB_DIR)

clean:
	$(RM) $(OBJS) $(NAME)
	make clean -C $(MLX_DIR)
	make clean -C $(LIB_DIR)
	
fclean: clean
	$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
