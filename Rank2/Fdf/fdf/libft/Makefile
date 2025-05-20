# VARIABLE_NAME = value (variable assignment)
#   $(VARIABLE_NAME) -> variable reference
# VARIABLE_NAME := value (immediate variable assignment)

# Compiler = tool used to compile the code
# Flags = options passed to the compiler
# Archiver = tool used to create archive files (combined into a single file for easier distribution and storage)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

SOURCES = \
    ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
    ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
    ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
    ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
    ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c \
    ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
    ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
    get_next_line.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putunbr.c \
    ft_putnbr_base.c ft_puthex.c ft_putptr.c ft_putstr.c 

# Variable substitution = replace .c with .o
OBJECTS = $(SOURCES:.c=.o)

# Output library name
NAME = libft.a

# TARGETS = files that make will create
# | target: prerequisites (dependencies)
# |     recipe (commands)

##############################################
#                Compilation Rules           #
##############################################

# Link all object files into the library archive
# Pattern rules = rules that can be used to generate multiple targets
# % = wildcard (matches any sequence of characters)
# %.o: %.c = compile .c files into .o files
# -c = compile only
# $< = only first dependency/prerequisite
# -o = output file
# $@ = target (name of the file) -> %.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files into the library archive
# $@ = target (name of the file) -> $(NAME)
# $^ = all dependencies/prerequisites (files that the target depends on) -> $(OBJECTS)
# rcs =
#   r (replace) -> any previous copies of the file
#   c (create) -> the archive if it does not exist
#   s (index) -> to the archive (to speed up searches)
$(NAME): $(OBJECTS)
	$(AR) rcs $@ $^

##############################################
#               Main Commands                #
##############################################

# Default target, builds the library
# Default target = first target in the file
# all =
# $ = variable
all: $(NAME)

##############################################
#             Cleaning Commands              #
##############################################

# Clean target (remove object files)
# rm = remove
# -f = force (no prompt nor error with nonexistent files and arguments)
clean:
	rm -f $(OBJECTS)

# Full clean target (remove everything built by make) -> object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild target (clean and build) -> clean + all
re: fclean all

##############################################
#                Phony Targets               #
##############################################

# Clarifies that these are rules
# Phony targets = not real files used as commands
.PHONY: all clean fclean re

# Shared library (.so) target
# so = shared object
so: re
	rm -f libft.so
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS)
