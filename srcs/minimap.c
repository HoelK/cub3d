/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:40:56 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 20:24:10 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	normalize_tidle(t_point px)
{
	px.x = px.x * (TIDLE_SIZE + 1);
	px.y = px.y * (TIDLE_SIZE + 1);
	return (px);
}

t_point	normalize_player(t_point px)
{
	px.x = (px.x * (TIDLE_SIZE + 1)) + (TIDLE_SIZE / 2) - (PLAYER_SIZE / 2);
	px.y = (px.y * (TIDLE_SIZE + 1)) + (TIDLE_SIZE / 2) - (PLAYER_SIZE / 2);
	return (px);
}

void	draw_map(t_display *display, char **map, t_point player)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] != '\n' && map[y][x])
		{
			color = WHITE;
			if (map[y][x] == '1')
				color = GREY;
			if (map[y][x] != ' ')
				draw_square(&display->minimap, normalize_tidle(get_point(x, y)),
					TIDLE_SIZE, color);
			if (x == player.x && y == player.y)
				draw_square(&display->minimap, normalize_tidle(get_point(x, y)),
					PLAYER_SIZE, ORANGE);
			x++;
		}
		x = 0;
		y++;
	}
}

void	img_to_frame(t_img *frame, t_img *img, int height, int width, int place_x, int place_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	x = 0;
	while (y < height)
	{
		while (x < width)
		{
			color = *(int *)(img->addr + (y * img->line_length
						+ x * (img->bits_per_pixel / 8)));
			if ((color & 0xFF000000) == 0 && color != 0)
				my_mlx_pixel_put(frame, get_point(x + place_x, y + place_y), color);
			x++;
		}
		x = 0;
		y++;
	}
}
