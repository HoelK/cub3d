/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 04:07:22 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 18:17:45 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda(t_ddata *dda, t_point player, t_point dir)
{
	dda->delta = get_delta(dir);
	dda->map_x = (int)player.x;
	dda->map_y = (int)player.y;
	dda->step_x = 1;
	dda->step_y = 1;
	dda->side_dist.y = (dda->map_y + 1.0 - player.y) * dda->delta.y;
	dda->side_dist.x = (dda->map_x + 1.0 - player.x) * dda->delta.x;
	if (dir.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = (player.x - dda->map_x) * dda->delta.x;
	}
	if (dir.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = (player.y - dda->map_y) * dda->delta.y;
	}
}

static void	update_dda(t_ddata *dda, char mod)
{
	if (mod == 'X')
	{
		dda->side_dist.x += dda->delta.x;
		dda->map_x += dda->step_x;
		dda->side = false;
	}
	if (mod == 'Y')
	{
		dda->side_dist.y += dda->delta.y;
		dda->map_y += dda->step_y;
		dda->side = true;
	}
}

t_ddata	dda(t_point player, char **map, t_ray *ray)
{
	t_ddata	dda;

	ft_bzero(&dda, sizeof(dda));
	init_dda(&dda, player, ray->dir);
	while (map[dda.map_y][dda.map_x] != '1')
	{
		if (dda.side_dist.x < dda.side_dist.y)
			update_dda(&dda, 'X');
		else
			update_dda(&dda, 'Y');
	}
	dda.wall_dist = get_walldist(&dda, player, ray->dir);
	dda.hit_pos.x = player.x + ray->dir.x * dda.wall_dist;
	dda.hit_pos.y = player.y + ray->dir.y * dda.wall_dist;
	dda.wall_x = get_wallx(&dda, ray->dir, player);
	dda.wall_x -= floor(dda.wall_x);
	return (dda);
}
