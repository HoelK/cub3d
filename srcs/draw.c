#include "cub3d.h"

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

