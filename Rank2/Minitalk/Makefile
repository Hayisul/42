# **************************************************************************** #
#                               Minitalk Makefile                             #
# **************************************************************************** #

NAME_CLIENT  = client
NAME_SERVER  = server
BNAME_CLIENT = client_bonus
BNAME_SERVER = server_bonus

CC     = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

INCLUDES = -Iinc -Ilibft/inc

SRC_CLIENT  = src/client.c
SRC_SERVER  = src/server.c
SRC_BCLIENT = src/client_bonus.c
SRC_BSERVER = src/server_bonus.c

OBJ_CLIENT  = $(SRC_CLIENT:.c=.o)
OBJ_SERVER  = $(SRC_SERVER:.c=.o)
OBJ_BCLIENT = $(SRC_BCLIENT:.c=.o)
OBJ_BSERVER = $(SRC_BSERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(BNAME_CLIENT) $(BNAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT_A) -o $@

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT_A) -o $@

$(BNAME_CLIENT): $(OBJ_BCLIENT) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_BCLIENT) $(LIBFT_A) -o $@

$(BNAME_SERVER): $(OBJ_BSERVER) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_BSERVER) $(LIBFT_A) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BCLIENT) $(OBJ_BSERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(BNAME_CLIENT) $(BNAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re