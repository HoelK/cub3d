/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:40:56 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/12 19:57:13 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

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

static int	get_map_color(char **map, t_ipoint coo)
{
	int	color;

	color = WHITE;
	if (map[coo.y][coo.x] == '1')
		color = GREY;
	else if (map[coo.y][coo.x] == 'D' || map[coo.y][coo.x] == 'd')
		color = BLUE;
	return (color);
}

void	draw_map(t_display *display, char **map, t_point player)
{
	t_ipoint	coo;

	coo.x = 0;
	coo.y = 0;
	while (map[coo.y])
	{
		while (map[coo.y][coo.x] != '\n' && map[coo.y][coo.x])
		{
			if (map[coo.y][coo.x] != ' ')
				draw_square(&display->minimap,
					normalize_tidle(get_point(coo.x, coo.y)),
					TIDLE_SIZE, get_map_color(map, coo));
			if (coo.x == player.x && coo.y == player.y)
				draw_square(&display->minimap,
					normalize_tidle(get_point(coo.x, coo.y)),
					PLAYER_SIZE, ORANGE);
			coo.x++;
		}
		coo.x = 0;
		coo.y++;
	}
}

void	img_to_frame(t_img *frame, t_img *img, t_point	h_and_w, t_point place)
{
	t_ipoint	coo;
	int			color;

	coo.y = 0;
	coo.x = 0;
	while (coo.y < h_and_w.y)
	{
		while (coo.x < h_and_w.x)
		{
			color = *(int *)(img->addr + (coo.y * img->line_length
						+ coo.x * (img->bits_per_pixel / 8)));
			if ((color & 0xFF000000) == 0 && color != 0)
				my_mlx_pixel_put(frame,
					get_point(coo.x + (int)place.x,
						coo.y + (int)place.y), color);
			coo.x++;
		}
		coo.x = 0;
		coo.y++;
	}
}
