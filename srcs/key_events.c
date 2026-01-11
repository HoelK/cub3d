/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:53:20 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 16:38:22 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(t_game *game)
{
	if (game->keys[KLEFT_ID])
		turn_left(game, 0, false);
	if (game->keys[KRIGHT_ID])
		turn_right(game, 0, false);
	if (game->keys[KW_ID])
		move_forward(game);
	if (game->keys[KS_ID])
		move_backward(game);
	if (game->keys[KD_ID])
		move_right(game);
	if (game->keys[KA_ID])
		move_left(game);
	if (game->keys[MCLICKL_ID])
		update_frame(game);
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
	else if (keypress == KEY_W)
		game->keys[KW_ID] = true;
	else if (keypress == KEY_S)
		game->keys[KS_ID] = true;
	else if (keypress == KEY_A)
		game->keys[KA_ID] = true;
	else if (keypress == KEY_D)
		game->keys[KD_ID] = true;
	return (0);
}

int	key_release(int keypress, t_game *game)
{
	if (keypress == KEY_LEFT)
		game->keys[KLEFT_ID] = false;
	else if (keypress == KEY_RIGHT)
		game->keys[KRIGHT_ID] = false;
	else if (keypress == KEY_W)
		game->keys[KW_ID] = false;
	else if (keypress == KEY_S)
		game->keys[KS_ID] = false;
	else if (keypress == KEY_A)
		game->keys[KA_ID] = false;
	else if (keypress == KEY_D)
		game->keys[KD_ID] = false;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	s_x;

	(void) y;
	if (s_x < x)
		turn_right(game, x - s_x, true);
	else if (s_x > x)
		turn_left(game, s_x - x, true);
	s_x = x;
	return (1);
}

int	mouse_click(int keypress, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (keypress == MCLICK_L)
		game->keys[MCLICKL_ID] = true;
	return (1);
}

void	hooks(t_game *game)
{
	mlx_hook(game->display.window, KPRESS, KPRESSMASK, key_press, game);
	mlx_hook(game->display.window, KREL, KRELMASK, key_release, game);
	mlx_hook(game->display.window, DESTROY, BPRESSMASK, close_game, game);
	mlx_mouse_hook(game->display.window, mouse_click, game);
	mlx_hook(game->display.window, MOTION, PMOTIONMASK, mouse_move, game);
	mlx_loop_hook(game->display.main, render, game);
	mlx_loop(game->display.main);
}
