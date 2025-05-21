#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

t_2d	project_iso(t_point p, t_fdf *fdf)
{
    t_2d result;

	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= (fdf->zoom / 2);

    result.x = (int)((p.x - p.y) * cos(ISO_ANGLE));
    result.y = (int)((p.x + p.y) * sin(ISO_ANGLE) - p.z);
    return (result);
}

void	center_map(t_fdf *fdf)
{
	t_point	center;
	t_2d	proj;

	center.x = fdf->map.width / 2;
	center.y = fdf->map.height / 2;
	center.z = 0;

	proj = project_iso(center, fdf);

	fdf->shift_x = (WINDOW_WIDTH / 2) - proj.x;
	fdf->shift_y = (WINDOW_HEIGHT / 2) - proj.y;
}
