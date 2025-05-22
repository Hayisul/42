# **************************************************************************** #
#                              LIBFT MAKEFILE                                  #
# **************************************************************************** #

# **************************************************************************** #
#                              LIBFT MAKEFILE                                  #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I. -Iinc

SRC         = src/ft_atoi.c \
             src/ft_bzero.c \
			 src/ft_calloc.c \
			 src/ft_memcpy.c \
             src/ft_memset.c \
			 src/ft_split.c \
             src/ft_strchr.c \
			 src/ft_strdup.c \
			 src/ft_strjoin.c \
			 src/ft_strlen.c \
			 src/get_next_line.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re