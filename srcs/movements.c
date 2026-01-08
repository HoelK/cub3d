/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:53:11 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/08 02:44:19 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_game *game)
{
	game->player.angle -= ROTATE_SPEED;
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
}

void	move_right(t_game *game)
{
	game->player.angle += ROTATE_SPEED;
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
}

void	move_forward(t_game *game)
{
	game->player.pos.x += game->player.dir.x * MOVE_SPEED;
	if (game->data.map[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
		game->player.pos.x -= game->player.dir.x * MOVE_SPEED;
	game->player.pos.y += game->player.dir.y * MOVE_SPEED;
	if (game->data.map[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
		game->player.pos.y -= game->player.dir.y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	game->player.pos.x += -game->player.dir.x * MOVE_SPEED;
	if (game->data.map[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
		game->player.pos.x -= -game->player.dir.x * MOVE_SPEED;
	game->player.pos.y += -game->player.dir.y * MOVE_SPEED;
	if (game->data.map[(int)game->player.pos.y][(int)game->player.pos.x] == '1')
		game->player.pos.y -= -game->player.dir.y * MOVE_SPEED;
}
