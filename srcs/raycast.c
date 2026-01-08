/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:38:26 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/08 01:08:01 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game)
{
	t_point	end;

	end = dda(game->player.pos, game->player.dir, game->data.map);
	draw_line(&game->display, normalize_tidle(game->player.pos),
		normalize_tidle(end), ORANGE);
}
