#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

// Constants
# define ESC 53	//adapt keycode for linux (maybe 65307)
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define ISO_ANGLE 0.523599

// 2D screen coordinate
typedef struct s_2d
{
	int	x;
	int	y;
}	t_2d;

// 3D point from the map
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

// Line structure
typedef struct s_line
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

// Map structure
typedef struct s_map
{
	t_point	**grid;
	int		width;
	int		height;
}	t_map;

// Master struct (holds everything)
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		zoom;
	int		shift_x;
	int		shift_y;
}	t_fdf;

void	parse_map(const char *filename, t_map *map);
void	draw_map(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_2d a, t_2d b, int color);
void	center_map(t_fdf *fdf);
int		get_color(int z);
int		ft_abs(int n);
t_2d	project_iso(t_point p, t_fdf *fdf);

#endif