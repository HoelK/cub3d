#include "cub3d.h"

void raycast(t_display *display, t_point player, t_point dir)
{
	t_point start;

	start.x = dir.x;
	start.y = dir.y;
	print_point(dir, "dir");
	print_point(player, "pos");
	start = rotate_point_around(player, start, 0.1745);
	draw_line(display, normalize_player(player), normalize_player(start), ORANGE);
	/*for (int i = 0; i < (FOV / 10) + 1; i++)
	{
		start = rotate_point_around(player, start, 0.1745);
		draw_line(display, normalize_player(player), normalize_player(start), ORANGE);
	}*/
}
