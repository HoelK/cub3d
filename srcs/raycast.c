#include "cub3d.h"

void raycast(t_display *display, t_point player)
{
	t_point start;

	start.x = player.x - 1;
	start.y = player.y;

	for (int i = 0; i < 5; i++)
	{
		start = rotate_point_around(player, start, 0.1745);
		draw_square(display, normalize_player(start), 3, ORANGE);
	}
}
