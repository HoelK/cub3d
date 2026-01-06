#include "cub3d.h"
#define MOVE_SPEED 0.1

void	move_left(t_game *game)
{
	game->player.dir = rotate_point_around(game->player.pos, game->player.dir, -0.174533);
}

void	move_right(t_game *game)
{
	game->player.dir = rotate_point_around(game->player.pos, game->player.dir, 0.174533);
}

void	move_forward(t_game *game)
{
	float dx = (game->player.dir.x - game->player.pos.x) * MOVE_SPEED;
	float dy = (game->player.dir.y - game->player.pos.y) * MOVE_SPEED;

	game->player.pos.x += dx;
	game->player.pos.y += dy;
	game->player.dir.x += dx;
	game->player.dir.y += dy;
}

int	handle_input(int keypress, t_game *game)
{
	if (keypress == KEY_ESC)
		close_game(game);
	else if (keypress == KEY_LEFT)
		move_left(game);
	else if (keypress == KEY_RIGHT)
		move_right(game);
	else if (keypress == KEY_UP)
		move_forward(game);
	return (0);
}

void	hooks(t_game *game)
{
	mlx_key_hook(game->display.window, handle_input, game);
	mlx_hook(game->display.window, DESTROY, BPRESSMASK, close_game, game);
	mlx_loop_hook(game->display.main, render, game);
	mlx_loop(game->display.main);
}
