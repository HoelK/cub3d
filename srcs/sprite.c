/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:39:34 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 16:38:04 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_frame(t_game *game)
{
	game->display.sprite.current_frame++;
	if (game->display.sprite.current_frame == FRAME_AMOUNT)
	{
		game->display.sprite.current_frame = 0;
		game->keys[MCLICKL_ID] = false;
	}
}

void	destroy_sprites(t_display *display)
{
	int	i;

	i = 0;
	while (i < FRAME_AMOUNT)
	{
		if (display->sprite.frames[i].img)
			mlx_destroy_image(display->main, display->sprite.frames[i].img);
		i++;
	}
}

bool	init_sprite(t_display *display)
{
	int		i;
	char	*num;
	char	*path;
	char	*f_path;

	i = -1;
	ft_bzero(&display->sprite, sizeof(t_sprite));
	while (++i < FRAME_AMOUNT)
	{
		num = ft_itoa(i);
		path = ft_strjoin(SPRITE_PATH, num);
		f_path = ft_strjoin(path, ".xpm");
		free(path);
		free(num);
		fprintf(stderr, "%s\n", f_path);
		display->sprite.frames[i].img = mlx_xpm_file_to_image(display->main,
				f_path, &display->sprite.frames[i].width, &display->sprite.frames[i].height);
		if (!display->sprite.frames[i].img)
			return (false);
		display->sprite.frames[i].addr = mlx_get_data_addr(display->sprite.frames[i].img,
				&display->sprite.frames[i].bits_per_pixel,
				&display->sprite.frames[i].line_length,
				&display->sprite.frames[i].endian);
		if (!display->sprite.frames[i].addr)
			return (false);
		free(f_path);
	}
	return (true);
}
