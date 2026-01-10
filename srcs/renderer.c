/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:39:36 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 02:25:57 by hkeromne         ###   ########.fr       */
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
	draw_ceil(&game->display, rgb_to_hex(game->data.colors[CEIL]));
	draw_floor(&game->display, rgb_to_hex(game->data.colors[FLOOR]));
	raycast(game);
	frame_timer(game);
	mlx_put_image_to_window(game->display.main, game->display.window,
		game->display.frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
