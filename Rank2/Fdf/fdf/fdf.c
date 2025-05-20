#include "fdf.h"

static void exit_fdf(t_fdf *fdf)
{
    if (fdf->win)
        mlx_destroy_window(fdf->mlx, fdf->win);
    exit(EXIT_SUCCESS);
}

static int handle_close(t_fdf *fdf)
{
    exit_fdf(fdf);
    return (0);
}

int	handle_key(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (keycode == ARROW_LEFT)
		fdf->shift_x -= 10;
	else if (keycode == ARROW_RIGHT)
		fdf->shift_x += 10;
	else if (keycode == ARROW_DOWN)
		fdf->shift_y += 10;
	else if (keycode == ARROW_UP)
		fdf->shift_y -= 10;

	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

int main(int argc, char **argv)
{
    t_fdf fdf;

    if (argc != 2)
    {
        write(2, "Usage: ./fdf <map.fdf>\n", 24);
        return (1);
    }
    parse_map(argv[1], &fdf.map);
	fdf.zoom = 20;
    
    fdf.mlx = mlx_init();
    if (!fdf.mlx)
        return (1);
    fdf.win = mlx_new_window(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf");
    if (!fdf.win)
        return (1);

    center_map(&fdf);
    draw_map(&fdf);

    mlx_hook(fdf.win, 2, 0, handle_key, &fdf);      // key press
    mlx_hook(fdf.win, 17, 0, handle_close, &fdf);   // close window
    mlx_loop(fdf.mlx);
    return (0);
}
