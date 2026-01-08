/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:38:26 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/08 04:07:01 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	angle_to_radian(int angle)
{
	return (angle * (PI / 180.0));
}

void	show(t_img *img, t_ddata dda, int x_pos)
{
	int		i;
	t_point	px;
	int		line_h;
	int		draw_end;
	int		draw_start;

	line_h = (int)(RES_Y / dda.perpWallDist);
	draw_start = -line_h / 2 + RES_Y / 2;
	draw_end = line_h / 2 + RES_Y / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= RES_Y)
		draw_end = RES_Y - 1;
	px.x = x_pos;
	i = draw_start - 1;
	while (i++ < draw_end)
	{
		px.y = i;
		my_mlx_pixel_put(img, px, ORANGE);
	}
}

void	draw_ceil(t_display *display, int color)
{
	int	y;

	y = -1;
	while (++y < (RES_Y / 2))
		draw_line(display, get_point(0, y),
			get_point(display->frame.line_length, y), color);
}

void	draw_floor(t_display *display, int color)
{
	int	x;

	x = RES_Y / 2;
	while (++x < (RES_Y))
		draw_line(display, get_point(0, x),
			get_point(display->frame.line_length, x), color);
}

int	rgb_to_hex(uint8_t *rgb)
{
	return (((rgb[R] & 0xff) << 16) + ((rgb[G] & 0xff) << 8) + (rgb[B] & 0xff));
}

void	raycast(t_game *game)
{
	int		i;
	t_ddata	dda_data;
	float	angle;
	float	off;
	t_point	raydir;

	i = -1;
	draw_ceil(&game->display, rgb_to_hex(game->data.colors[CEIL]));
	draw_floor(&game->display, rgb_to_hex(game->data.colors[FLOOR]));
	angle = game->player.angle;
	raydir.x = cos(angle);
	raydir.y = sin(angle);
	dda_data = dda(game->player.pos, raydir, game->data.map);
	//draw_line(&game->display, normalize_tidle(game->player.pos),
	//	normalize_tidle(dda_data.hit_pos), ORANGE);
	while (++i < RES_X)
	{
		off = game->player.angle - angle_to_radian(FOV) / 2.0
			+ i * (angle_to_radian(FOV) / (RES_X - 1));
		raydir.x = cos(off);
		raydir.y = sin(off);
		show(&game->display.frame, dda_data, i);
		dda_data = dda(game->player.pos, raydir, game->data.map);
		//draw_line(&game->display, normalize_tidle(game->player.pos),
		///		normalize_tidle(dda_data.hit_pos), ORANGE);
	}
}
