/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:42:57 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 05:28:28 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_textures(t_display *display, t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		display->texture[i].img = mlx_xpm_file_to_image(display->main,
				data->texture_path[i],
				&display->texture[i].width,
				&display->texture[i].height);
		if (!display->texture[i].img)
			return (false);
		display->texture[i].addr = mlx_get_data_addr(display->texture[i].img,
				&display->texture[i].bits_per_pixel,
				&display->texture[i].line_length,
				&display->texture[i].endian);
		if (!display->texture[i].addr)
			return (false);
	}
	return (true);
}

bool	init_display(t_display *display, t_data *data)
{
	display->main = mlx_init();
	if (!display->main)
		return (false);
	display->window = mlx_new_window(display->main, RES_X, RES_Y, "cub3d");
	if (!display->window)
		return (false);
	display->frame.img = mlx_new_image(display->main, RES_X, RES_Y);
	if (!display->frame.img)
		return (false);
	display->frame.addr = mlx_get_data_addr(display->frame.img,
			&display->frame.bits_per_pixel,
			&display->frame.line_length,
			&display->frame.endian);
	if (!display->frame.addr)
		return (false);
	display->minimap.height = ft_doublelen(data->map) * (TIDLE_SIZE + 1);
	display->minimap.width = (ft_strlen(data->map[0]) - 1) * (TIDLE_SIZE + 1);
	display->minimap.img = mlx_new_image(display->main,
		display->minimap.width,
		display->minimap.height);
	if (!display->minimap.img)
		return (false);
	display->minimap.addr = mlx_get_data_addr(display->minimap.img,
			&display->minimap.bits_per_pixel,
			&display->minimap.line_length,
			&display->minimap.endian);
	if (!display->minimap.addr)
		return (false);
	if (!init_textures(display, data))
		return (false);
	return (true);
}

void	kill_display(t_display *display)
{
	int	i;

	i = -1;
	if (display->frame.img)
		mlx_destroy_image(display->main, display->frame.img);
	if (display->minimap.img)
		mlx_destroy_image(display->main, display->minimap.img);
	while (++i < 4)
	{
		if (display->texture[i].img)
			mlx_destroy_image(display->main, display->texture[i].img);
	}
	if (display->window)
		mlx_destroy_window(display->main, display->window);
	if (display->main)
		mlx_destroy_display(display->main);
	free(display->main);
}

void	ft_kill(t_game *game, uint8_t status)
{
	delete_data(&game->data);
	kill_display(&game->display);
	exit (status);
}

int	close_game(t_game *game)
{
	ft_kill((t_game *)game, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
