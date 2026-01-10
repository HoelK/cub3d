/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 02:47:41 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 02:47:46 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_game *game)
{
	game->player.angle -= ROTATE_SPEED;
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
	game->player.cplane.x = -game->player.dir.y;
	game->player.cplane.y = game->player.dir.x;
}

void	turn_right(t_game *game)
{
	game->player.angle += ROTATE_SPEED;
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
	game->player.cplane.x = -game->player.dir.y;
	game->player.cplane.y = game->player.dir.x;
}
