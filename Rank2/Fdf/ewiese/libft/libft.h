/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:31:37 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/12/18 19:31:57 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>  // Funciones de caracteres
# include <limits.h> // Definiciones de límites de tipo
# include <stdarg.h> // Funciones para evaluar los argumentos input
# include <stddef.h> // Funciones de las variables y macros
# include <stdio.h>  //Funciones para imprimir los errores (como perror));
# include <stdlib.h> // Utilidades generales
# include <string.h> // Funciones de cadena y memoria
# include <unistd.h> // Funciones de sistema

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Bloque 1: Funciones de caracteres
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isxdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

// Bloque 2: Funciones de cadena y memoria
void					*ft_memset(void *s, int c, size_t n);
size_t					ft_strlen(const char *s);
void					ft_bzero(void *s, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strdup(const char *s);
char					*ft_strcpy(char *dest, const char *src);

// Bloque 3: Conversión y asignación de memoria
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);

// Bloque 4: Funciones avanzadas de cadena
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
long					ft_strtol(const char *str, int str_base);

// Bloque 5: Funciones de listas enlazadas
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

// Bloque 6: Funciones del Printf
int						ft_printchar(int c);
int						ft_printstr(char *str);
int						ft_printnbr_hex(unsigned long nbr, char flag);
int						ft_printnbr_unsigned(unsigned int nbr);
int						ft_printnbr(int nbr);
int						ft_printptr(unsigned long long ptr);
int						ft_printf(const char *string, ...);

// Bloque 7: Funciones del get_next_line

typedef struct s_gnl_list
{
	char				*str_buffer;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						ft_found_newline(t_gnl_list *list);
t_gnl_list				*ft_find_last_node(t_gnl_list *list);
char					*get_line(t_gnl_list *list);
void					ft_copy_str(t_gnl_list *list, char *str);
int						ft_len_to_newline(t_gnl_list *list);
void					polish_list(t_gnl_list **list);
char					*get_next_line(int fd);
void					ft_dealloc(t_gnl_list **list, t_gnl_list *clean_node,
							char *buf);
void					create_list(t_gnl_list **list, int fd);
void					append(t_gnl_list **list, char *buf);

#endif
