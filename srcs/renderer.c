/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:39:36 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 15:58:08 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

static void	frame_timer(t_game *game)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	while ((get_time() - game->time) < 16)
		;
	game->time = get_time();
}

int	render(t_game *game)
{
	handle_input(game);
	draw_map(&game->display, game->data.map, game->player.pos);
	draw_ceil(&game->display.frame, rgb_to_hex(game->data.colors[CEIL]));
	draw_floor(&game->display.frame, rgb_to_hex(game->data.colors[FLOOR]));
	raycast(game);
	img_to_frame(&game->display.frame, &game->display.minimap,
		game->display.minimap.height,
		game->display.minimap.width, 0, 0);
	img_to_frame(&game->display.frame,
		&game->display.sprite.frames[game->display.sprite.current_frame],
		game->display.sprite.frames[game->display.sprite.current_frame].height,
		game->display.sprite.frames[game->display.sprite.current_frame].width,
		RES_X - game->display.sprite.frames[game->display.sprite.current_frame].width,
		RES_Y - game->display.sprite.frames[game->display.sprite.current_frame].height - 65);
	frame_timer(game);
	mlx_put_image_to_window(game->display.main, game->display.window,
		game->display.frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
