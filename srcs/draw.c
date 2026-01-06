#include "cub3d.h"

void	draw_line(t_display *disp, t_point start, t_point end, int color)
{
	double	delta_x;
	double	delta_y;
	double	pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	if (fabs(delta_x) > fabs(delta_y))
		pixels = fabs(delta_x);
	else
		pixels = fabs(delta_y);
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start.x;
	pixel_y = start.y;
	while (pixels > 0)
	{
		my_mlx_pixel_put(&disp->frame, get_point(pixel_x, pixel_y), color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_square(t_display *display, t_point start, int size, int color)
{
	t_point	px;

	px.x = start.x;
	px.y = start.y;
	while ((px.y - start.y) < size)
	{
		while ((px.x - start.x) < size)
		{
			my_mlx_pixel_put(&display->frame, px, color);
			px.x++;
		}
		px.x = start.x;
		px.y++;
	}
}

