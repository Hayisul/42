# Variables
NAME        = fdf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes
MLX_DIR     = minilibx
LIBFT_DIR   = libft
MLX_LINK    = -L$(MLX_DIR) -lmlx -lXext -lX11
LIBFT_LINK  = $(LIBFT_DIR)/libft.a
MATH_FLAGS  = -lm

SRCS        = bresenham.c \
              check_valid.c \
              draw_landscape.c \
              init_matrix.c \
              main.c \
              utils.c \
              key_controls.c \

OBJS        = $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINK) $(LIBFT_LINK) $(MATH_FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

# Utilidad para mantener consistencia
.PHONY: all clean fclean re

