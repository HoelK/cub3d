#include "cub3d.h"
# define CROSSHAIR_LINE_THICK	1
# define CROSSHAIR_LINE_LEN		4
# define CENTER_OFFSET			2
# define ROSE_PETANT			0xFD6C9E

void	draw_rectangle(t_img *img, t_point pos, int len, int hei)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	while ((y - pos.y) < hei)
	{
		while ((x - pos.x) < len)
		{
			my_mlx_pixel_put(img, get_point(x, y), ROSE_PETANT);
			x++;
		}
		x = pos.x;
		y++;
	}
}

void	render_crossair(t_game *game)
{
	draw_rectangle(&game->display.frame, get_point((RES_X / 2) - CROSSHAIR_LINE_LEN - CENTER_OFFSET, (RES_Y / 2)), CROSSHAIR_LINE_LEN, CROSSHAIR_LINE_THICK);
	draw_rectangle(&game->display.frame, get_point((RES_X / 2) + CROSSHAIR_LINE_THICK + CENTER_OFFSET, (RES_Y / 2)), CROSSHAIR_LINE_LEN, CROSSHAIR_LINE_THICK);
	draw_rectangle(&game->display.frame, get_point((RES_X / 2), (RES_Y / 2) - CROSSHAIR_LINE_LEN - CENTER_OFFSET), CROSSHAIR_LINE_THICK, CROSSHAIR_LINE_LEN);
	draw_rectangle(&game->display.frame, get_point((RES_X / 2), (RES_Y / 2) + CROSSHAIR_LINE_THICK + CENTER_OFFSET), CROSSHAIR_LINE_THICK, CROSSHAIR_LINE_LEN);
}
