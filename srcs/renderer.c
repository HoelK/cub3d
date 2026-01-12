/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:39:36 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/12 02:15:08 by hkeromne         ###   ########.fr       */
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

static void	ui(t_display *display)
{
	img_to_frame(&display->frame, &display->minimap,
		get_point(
			display->minimap.width,
			display->minimap.height),
		get_point(0, 0));
	img_to_frame(&display->frame,
		&display->gun.frames[display->gun.current_frame],
		get_point(
			display->gun.frames[display->gun.current_frame].width,
			display->gun.frames[display->gun.current_frame].height),
		get_point(
			RES_X - display->gun.frames[display->gun.current_frame].width,
			RES_Y - display->gun.frames[display->gun.current_frame].height
			- 65));
}

int	render(t_game *game)
{
	//mlx_mouse_hide(game->display.main, game->display.window); //cause leaks
	handle_input(game);
	draw_ceil(&game->display.frame, rgb_to_hex(game->data.colors[CEIL]));
	draw_floor(&game->display.frame, rgb_to_hex(game->data.colors[FLOOR]));
	draw_map(&game->display, game->data.map, game->player.pos);
	raycast(game);
	ui(&game->display);
	render_crossair(game);
	frame_timer(game);
	mlx_put_image_to_window(game->display.main, game->display.window,
		game->display.frame.img, 0, 0);
	return (EXIT_SUCCESS);
}
