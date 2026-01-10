/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:39:53 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 04:26:36 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, t_point px, int color)
{
	char	*dst;

	dst = data->addr + ((int)px.y * data->line_length
			+ (int)px.x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceil(t_img *frame, int color)
{
	int	y;

	y = -1;
	while (++y < (RES_Y / 2))
		draw_line(frame, get_point(0, y),
			get_point(frame->line_length, y), color);
}

void	draw_floor(t_img *frame, int color)
{
	int	x;

	x = RES_Y / 2;
	while (++x < (RES_Y))
		draw_line(frame, get_point(0, x),
			get_point(frame->line_length, x), color);
}

void	draw_line(t_img *img, t_point start, t_point end, int color)
{
	t_point	delta;
	t_point	pixel;
	double	pixels;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	pixels = fabs(delta.y);
	if (fabs(delta.x) > fabs(delta.y))
		pixels = fabs(delta.x);
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = start.x;
	pixel.y = start.y;
	while (pixels > 0)
	{
		my_mlx_pixel_put(img, pixel, color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		pixels--;
	}
}

void	draw_square(t_img *img, t_point start, int size, int color)
{
	t_point	px;

	px.x = start.x;
	px.y = start.y;
	while ((px.y - start.y) < size)
	{
		while ((px.x - start.x) < size)
		{
			my_mlx_pixel_put(img, px, color);
			px.x++;
		}
		px.x = start.x;
		px.y++;
	}
}
