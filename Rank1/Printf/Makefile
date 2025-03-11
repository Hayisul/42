# Variables
NAME = libftprint.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_DIR = src
INC_DIR = include

SRCS = \
	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
	ft_puthex.c ft_putptr.c ft_putnbr_base.c ft_strlen.c\

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

# Default Target
all: $(NAME)

# Creating the Static Library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Pattern Rule
# -I = include directory
# -c = compile only
# -o = output file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_print.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Cleaning Object Files
clean:
	$(RM) $(OBJS)

# Full Clean
fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

# Phony Targets
.PHONY: all clean fclean re