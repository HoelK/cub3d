/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 04:07:22 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/08 04:07:37 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_point	get_delta(t_point dir)
{
	t_point	delta;

	delta.x = 1e30;
	delta.y = 1e30;
	if (dir.x != 0)
		delta.x = fabs(1 / dir.x);
	if (dir.y != 0)
		delta.y = fabs(1 / dir.y);
	return (delta);
}

static void	init_dda(t_ddata *dda, t_point player, t_point dir)
{
	dda->delta = get_delta(dir);
	dda->mapX = (int)player.x;
	dda->mapY = (int)player.y;
	dda->stepX = 1;
	dda->stepY = 1;
	dda->side_dist.y = (dda->mapY + 1.0 - player.y) * dda->delta.y;
	dda->side_dist.x = (dda->mapX + 1.0 - player.x) * dda->delta.x;
	if (dir.x < 0)
	{
		dda->stepX = -1;
		dda->side_dist.x = (player.x - dda->mapX) * dda->delta.x;
	}
	if (dir.y < 0)
	{
		dda->stepY = -1;
		dda->side_dist.y = (player.y - dda->mapY) * dda->delta.y;
	}
}

static void	update_dda(t_ddata *dda, char mod)
{
	if (mod == 'X')
	{
		dda->side_dist.x += dda->delta.x;
		dda->mapX += dda->stepX;
		dda->side = false;
	}
	if (mod == 'Y')
	{
		dda->side_dist.y += dda->delta.y;
		dda->mapY += dda->stepY;
		dda->side = true;
	}
}

static float	get_walldist(t_ddata *dda, t_point player, t_point dir)
{
	if (!dda->side)
		return ((dda->mapX - player.x + (1 - dda->stepX) / 2) / dir.x);
	return ((dda->mapY - player.y + (1 - dda->stepY) / 2) / dir.y);
}

t_ddata	dda(t_point player, t_point dir, char **map)
{
	t_ddata	dda;

	init_dda(&dda, player, dir);
	while (map[dda.mapY][dda.mapX] != '1')
	{
		if (dda.side_dist.x < dda.side_dist.y)
			update_dda(&dda, 'X');
		else
			update_dda(&dda, 'Y');
	}
	dda.perpWallDist = get_walldist(&dda, player, dir);
	dda.hit_pos.x = player.x + dir.x * dda.perpWallDist;
	dda.hit_pos.y = player.y + dir.y * dda.perpWallDist;
	return (dda);
}
