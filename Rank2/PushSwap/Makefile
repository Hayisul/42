# **************************************************************************** #
#                                PUSH_SWAP MAKEFILE                            #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O2 $(INCLUDES)

SRCS = \
       src/build/stack_builder.c \
       src/analyze/node_analysis.c \
       src/analyze/target_assignment.c \
       src/analyze/cost_analysis.c \
       src/sort/sort.c \
       src/sort/push_prep.c \
       src/operations/swap_ops.c \
       src/operations/push_ops.c \
       src/operations/rotate_ops.c \
       src/operations/reverse_ops.c \
       src/utils/stack_utils.c \
       src/utils/cleanup.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

INCLUDES    = -Iinc -Ilibft/inc

all: $(NAME)

$(NAME): $(OBJS) push_swap.o $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) push_swap.o $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) push_swap.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re