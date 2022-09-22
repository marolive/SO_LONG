NAME = libft.a
HEADER = libft.h
SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_itoa.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_bzero.c \
		get_next_line.c \
		get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 



.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	

re:	fclean all

.PHONY:	all clean fclean re
