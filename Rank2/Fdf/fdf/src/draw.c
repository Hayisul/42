#include "fdf.h"

static void put_pixel(t_fdf *fdf, int x, int y, int color)
{
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
        mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
}


static void	init_line(t_fdf *fdf, t_2d a, t_2d b, t_line *line)
{
    line->x = a.x + fdf->shift_x;
    line->y = a.y + fdf->shift_y;
    line->dx = ft_abs(b.x - a.x);
    line->dy = -ft_abs(b.y - a.y);
    if (a.x < b.x)
        line->sx = 1;
    else
        line->sx = -1;
    if (a.y < b.y)
        line->sy = 1;
    else
        line->sy = -1;
    line->err = line->dx + line->dy;
}

void draw_line(t_fdf *fdf, t_2d a, t_2d b, int color)
{
    t_line line;

    init_line(fdf, a, b, &line);
    while (line.x != b.x + fdf->shift_x || line.y != b.y + fdf->shift_y)
    {
        put_pixel(fdf, line.x, line.y, color);
        line.e2 = 2 * line.err;
        if (line.e2 >= line.dy)
        {
            line.err += line.dy;
            line.x += line.sx;
        }
        if (line.e2 <= line.dx)
        {
            line.err += line.dx;
            line.y += line.sy;
        }
    }
    put_pixel(fdf, line.x, line.y, color);
}

static void draw_links(t_fdf *fdf, int x, int y)
{
	t_2d a;
	t_2d b;
	int color;

	a = project_iso(fdf->map.grid[y][x], fdf);
	color = 0xFFFFFF;
	if (x < fdf->map.width - 1)
	{
		b = project_iso(fdf->map.grid[y][x + 1], fdf);
		draw_line(fdf, a, b, color);
	}
	if (y < fdf->map.height - 1)
	{
		b = project_iso(fdf->map.grid[y + 1][x], fdf);
		draw_line(fdf, a, b, color);
	}
}

void	draw_map(t_fdf *fdf)
{
    int y;
    int x;

    y = 0;
    while (y < fdf->map.height)
    {
        x = 0;
        while (x < fdf->map.width)
        {
            draw_links(fdf, x, y);
            x++;
        }
        y++;
    }
}
