#include "fdf.h"

int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

t_2d	project_iso(t_point p, t_fdf *fdf)
{
    t_2d result;

	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= (fdf->zoom / 3);

    result.x = (int)((p.x - p.y) * cos(ISO_ANGLE));
    result.y = (int)((p.x + p.y) * sin(ISO_ANGLE) - p.z);
    return (result);
}

void	center_map(t_fdf *fdf)
{
	int	map_width_px;
	int	map_height_px;

	map_width_px = (fdf->map.width + fdf->map.height) * fdf->zoom * cos(ISO_ANGLE);
	map_height_px = (fdf->map.width + fdf->map.height) * fdf->zoom * sin(ISO_ANGLE);

	fdf->shift_x = (WINDOW_WIDTH - map_width_px);
	fdf->shift_y = (WINDOW_HEIGHT - map_height_px) / 2;
}

int get_color(int z)
{
	if (z == 0)
		return (0xFFFFFF); // white for sea level
	else if (z < 10)
		return (0x00FF00); // green for low hills
	else if (z < 20)
		return (0x996600); // brown for higher ground
	else
		return (0xCCCCCC); // gray for peaks
}

int	interpolate(int start, int end, float percent)
{
	return ((int)(start + (end - start) * percent));
}

int	get_interpolated_color(int start, int end, float percent)
{
	int	r;
	int	g;
	int	b;

	r = interpolate((start >> 16) & 0xFF, (end >> 16) & 0xFF, percent);
	g = interpolate((start >> 8) & 0xFF, (end >> 8) & 0xFF, percent);
	b = interpolate(start & 0xFF, end & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}