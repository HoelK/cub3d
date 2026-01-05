#include "cub3d.h"

t_point	normalize_tidle(t_point px)
{
	px.x = px.x * (TIDLE_SIZE + 1);
	px.y = px.y * (TIDLE_SIZE + 1);
	return (px);
}

t_point	normalize_player(t_point px)
{
	px.x = (px.x * (TIDLE_SIZE + 1)) + (TIDLE_SIZE / 2) - (PLAYER_SIZE / 2);
	px.y = (px.y * (TIDLE_SIZE + 1)) + (TIDLE_SIZE / 2) - (PLAYER_SIZE / 2);
	return (px);
}

void	draw_map(t_display *display, char **map, t_point player)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = WHITE;
	while (map[y])
	{
		while (map[y][x] != '\n' && map[y][x])
		{
			color = WHITE;
			if (map[y][x] == '1')
				color = GREY;
			draw_square(display, normalize_tidle(get_point(x, y)), TIDLE_SIZE, color);
			if (x == player.x && y == player.y)
				draw_square(display, normalize_player(get_point(x, y)), PLAYER_SIZE, ORANGE);
			x++;
		}
		x = 0;
		y++;
	}
}

