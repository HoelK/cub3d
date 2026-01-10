/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:38:26 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 02:44:43 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_id(t_ddata dda, t_game *game)
{
	(void) game;
	if (dda.side == true)
	{
		if (dda.stepY < 0)
			return (EAST);
		return (WEST);
	}
	if (dda.stepX < 0)
		return (NORTH);
	return (SOUTH);
}

void	vertical_draw(t_game *game, t_ray ray)
{
	int		y;
	t_tex	tex;

	y = ray.line_start - 1;
	tex.id = get_texture_id(game->dda, game);
	tex.x = (int)(game->dda.wall_x
			* (double)(game->display.texture[tex.id].width));
	if (!game->dda.side && ray.dir.x > 0)
		tex.x = game->display.texture[tex.id].width - tex.x - 1;
	if (game->dda.side && ray.dir.y < 0)
		tex.x = game->display.texture[tex.id].width - tex.x - 1;
	tex.step = (double)game->display.texture[tex.id].height
		/ (double)ray.line_len;
	tex.pos = (double)(ray.line_start - RES_Y / 2 + ray.line_len / 2) *tex.step;
	while (++y < ray.line_end)
	{
		tex.y = (int)tex.pos;
		tex.pos += tex.step;
		tex.color = *(int *)(game->display.texture[tex.id].addr
				+ tex.y * game->display.texture[tex.id].line_length
				+ tex.x * 4);
		my_mlx_pixel_put(&game->display.frame, get_point(ray.id, y), tex.color);
	}
}

void	init_ray(t_ray *ray, t_ddata *dda)
{
	ray->line_len = (int)(RES_Y / dda->wall_dist);
	ray->line_start = -ray->line_len / 2 + RES_Y / 2;
	ray->line_end = ray->line_len / 2 + RES_Y / 2;
	if (ray->line_start < 0)
		ray->line_start = 0;
	if (ray->line_end >= RES_Y)
		ray->line_end = RES_Y - 1;
}

void	put_frame(t_game *game, t_ray ray)
{
	int		i;
	t_point	px;

	px.x = ray.id;
	init_ray(&ray, &game->dda);
	i = ray.line_start - 1;
	vertical_draw(game, ray);
}

void	raycast(t_game *game)
{
	int		i;
	float	offset;
	t_ray	ray;

	i = -1;
	while (++i < RES_X)
	{
		ray.id = i;
		offset = (float)(((2.0 * i) / RES_X) - 1);
		ray.dir.x = game->player.dir.x + game->player.cplane.x * offset;
		ray.dir.y = game->player.dir.y + game->player.cplane.y * offset;
		game->dda = dda(game->player.pos, game->data.map, &ray);
		put_frame(game, ray);
		// MINIMAP RAYS
		//draw_line(&game->display, normalize_tidle(game->player.pos),
		//		normalize_tidle(game->dda.hit_pos), ORANGE);
	}
}
