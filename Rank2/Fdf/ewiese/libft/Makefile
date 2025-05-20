# Nombre del archivo de la biblioteca
NAME	= 	libft.a

# Archivos fuente
SRC		= 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isxdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printchar.c \
			ft_printf.c \
			ft_printnbr.c \
			ft_printnbr_hex.c \
			ft_printnbr_unsigned.c \
			ft_printptr.c \
			ft_printstr.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strtol.c \
			get_next_line.c \
			get_next_line_utils.c
# Archivos objeto
OBJ 	=	$(SRC:.c=.o)

# Archivo de encabezado
HEAD 	=	libft.h

# Comandos
AR 		= 	ar -rcs
GCC 	= 	gcc
FLAGS 	= 	-Wall -Werror -Wextra

# Regla principal
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compilación de archivos .c a .o
.c.o:
	$(GCC) $(FLAGS) -I ./ -c $< -o ${<:.c=.o}	

# Limpieza de archivos objeto
clean:
	rm -f $(OBJ)

# Limpieza total
fclean: clean
	rm -f $(NAME)

# Regenerar todo
re: fclean all

# Indicar que las reglas no son archivos
.PHONY: clean fclean re all

