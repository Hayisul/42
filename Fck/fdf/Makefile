# **************************************************************************** #
#                                  FDF MAKEFILE                                #
# **************************************************************************** #

NAME        = fdf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror $(INCLUDES)

SRCS = \
       src/parse.c \
       src/draw.c \
       src/utils.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx
MLX_A       = $(MLX_DIR)/libmlx.a
MLXFLAGS    = -lXext -lX11 -lm -lbsd

INCLUDES    = -Iinc -I$(LIBFT_DIR)/inc -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) fdf.o $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) fdf.o $(LIBFT_A) $(MLX_A) $(MLXFLAGS) -o $(NAME)

fdf.o: fdf.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS) fdf.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
