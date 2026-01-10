/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:38:26 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 01:48:14 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define N_COL 0x008000 //green
#define S_COL 0		   //black
#define E_COL 0xFFA500 //
#define W_COL 0xFF0000 //red

int		get_texture_id(t_ddata dda, t_game *game)
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

void vertical_draw(t_game *game, t_ray ray)
{
	int     id;
	int     texX;
	int     texY;
	int     color;
	double  step;
	double  texPos;

	id = get_texture_id(game->dda, game);
	texX = (int)(game->dda.wall_x * (double)(game->display.texture[id].width));
	if (!game->dda.side && ray.dir.x > 0)
		texX = game->display.texture[id].width - texX - 1;
	if (game->dda.side && ray.dir.y < 0)
		texX = game->display.texture[id].width - texX - 1;
	step = (double)game->display.texture[id].height / (double)ray.line_len;
	texPos = (double)(ray.line_start - RES_Y / 2 + ray.line_len / 2) * step;
	for(int y = ray.line_start; y < ray.line_end; y++)
	{
		texY = (int)texPos;
		texPos += step;
		color = *(int *)(game->display.texture[id].addr + 
				texY * game->display.texture[id].line_length + texX * 4);
		my_mlx_pixel_put(&game->display.frame, get_point(ray.id, y), color);
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

void	show(t_game *game, t_ray ray)
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
		offset = (float)(((2.0 * i) / RES_X) - 1);
		ray.id = i;
		ray.dir.x = game->player.dir.x + game->player.cplane.x * offset;
		ray.dir.y = game->player.dir.y + game->player.cplane.y * offset;
		game->dda = dda(game->player.pos, game->data.map, &ray);
		show(game, ray);
		// MINIMAP RAYS
		//draw_line(&game->display, normalize_tidle(game->player.pos),
		//		normalize_tidle(dda_data.hit_pos), ORANGE);
	}
}
