/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:48:12 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/12/18 21:52:14 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ESC 65307
# define P 112
# define M 109
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_draw
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	float	length;
	float	step;
	float	t;
}			t_draw;

typedef struct s_gradient
{
	int		r0;
	int		g0;
	int		b0;
	int		r1;
	int		g1;
	int		b1;
	int		r;
	int		g;
	int		b;
}			t_gradient;

typedef struct s_mlx
{
	int		**arr;
	long	**color;
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	int		up_down;
	int		left_right;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits;
	int		line_len;
	int		endian;
}			t_mlx;

typedef struct s_landscape
{
	double	angle;
	int		pos;
	int		x_y[2];
	int		x1_y1[2];
}			t_landscape;

/******************DRAW FUNCTIONS************************************/
void		draw_line(t_mlx *data, int x0_y0[2], int x1_y1[2], int color[2]);
void		draw_landscape(t_mlx *data);

/******************INITIALIZATION_OF_MATRIX**************************/
void		init_matrix(t_mlx *data, char *file);

/******************CHECK_INPUT_FILE**********************************/
void		ft_check_input(char *file);

/******************HANDLE_ERRORS_AND_FREEING*************************/
void		ft_error_exit(char *msg);
void		ft_free(char **to_free);
void		free_matrix(t_mlx **data);
void		free_color(t_mlx **data);

/******************UTILS*********************************************/
int			get_x(char *line);
void		get_scale(t_mlx *data);

/*******************MLX_HOOK*****************************************/
void		control_moves(int keycode, t_mlx **img);

#endif
