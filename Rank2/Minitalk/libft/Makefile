# **************************************************************************** #
#                              LIBFT MAKEFILE                                  #
# **************************************************************************** #

NAME	= libft.a

SRC		= src/ft_atoi.c \
		  src/ft_putchar_fd.c \
		  src/ft_putnbr_fd.c \
		  src/ft_putstr_fd.c \
		  src/ft_strlen.c

OBJ		= $(SRC:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I. -Iinc
AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re