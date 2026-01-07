/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:53:20 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/07 21:53:20 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(t_game *game)
{
	if (game->keys[KLEFT_ID])
		move_left(game);
	else if (game->keys[KRIGHT_ID])
		move_right(game);
	else if (game->keys[KUP_ID])
		move_forward(game);
	else if (game->keys[KDOWN_ID])
		move_backward(game);
	return (0);
}

int	key_press(int keypress, t_game *game)
{
	if (keypress == KEY_ESC)
		close_game(game);
	else if (keypress == KEY_LEFT)
		game->keys[KLEFT_ID] = true;
	else if (keypress == KEY_RIGHT)
		game->keys[KRIGHT_ID] = true;
	else if (keypress == KEY_UP)
		game->keys[KUP_ID] = true;
	else if (keypress == KEY_DOWN)
		game->keys[KDOWN_ID] = true;
	return (0);
}

int	key_release(int keypress, t_game *game)
{
	if (keypress == KEY_LEFT)
		game->keys[KLEFT_ID] = false;
	else if (keypress == KEY_RIGHT)
		game->keys[KRIGHT_ID] = false;
	else if (keypress == KEY_UP)
		game->keys[KUP_ID] = false;
	else if (keypress == KEY_DOWN)
		game->keys[KDOWN_ID] = false;
	return (0);
}

void	hooks(t_game *game)
{
	mlx_hook(game->display.window, KPRESS, KPRESSMASK, key_press, game);
	mlx_hook(game->display.window, KREL, KRELMASK, key_release, game);
	mlx_hook(game->display.window, DESTROY, BPRESSMASK, close_game, game);
	mlx_loop_hook(game->display.main, render, game);
	mlx_loop(game->display.main);
}
