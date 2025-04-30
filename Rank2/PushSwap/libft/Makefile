# **************************************************************************** #
#                              LIBFT MAKEFILE                                  #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Iinc
AR          = ar rcs
RM          = rm -f

SRC         = src/ft_atol.c \
             src/ft_isdigit.c \
             src/ft_putchar_fd.c \
             src/ft_putnbr_fd.c \
             src/ft_putstr_fd.c \
             src/ft_split.c \
             src/ft_strlen.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re