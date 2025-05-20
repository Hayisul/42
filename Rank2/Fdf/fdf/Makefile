# **************************************************************************** #
#                                  FdF MAKEFILE                                #
# **************************************************************************** #

NAME        = fdf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g $(INCLUDES)

# Directories
INC_DIR     = inc
LIBFT_DIR   = libft
MLX_DIR     = minilibx_macos

# Libraries
LIBFT_A     = $(LIBFT_DIR)/libft.a
MLX_A       = $(MLX_DIR)/libmlx.a
MLXFLAGS    = -framework OpenGL -framework AppKit

# Includes
INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Sources
SRCS = \
	src/parse.c \
	src/draw.c \
	src/utils.c

# Objects
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) fdf.o $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) fdf.o $(LIBFT_A) $(MLX_A) $(MLXFLAGS) -o $(NAME)

fdf.o: fdf.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS) fdf.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re