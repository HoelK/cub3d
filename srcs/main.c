/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:35 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/20 19:38:35 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OFFSET (RES_X / 10)
#define WHITE 0xFFFFFF
#define ORANGE 0xFFA500

bool	init_display(t_display *display);
void	my_mlx_pixel_put(t_img *frame, int x, int y, int color);
void	kill_display(t_display *display);
void	ft_kill(t_display *display, t_data *data, uint8_t status);
void	put_buffer_line(t_display *display, int x, int y_start, int color);
void	draw_line(t_display *display, int x0, int y0, int x1, int y1, int color);
void	draw_square(t_display *display, int startx, int starty, int size, int color);

void	draw_square(t_display *display, int startx, int starty, int size, int color)
{
	int	len;
	int	wid;

	len = startx;
	wid = starty;
	while ((wid - starty) < size)
	{
		while ((len - startx) < size)
		{
			mlx_pixel_put(display->main, display->window, len, wid, color);
			len++;
		}
		len = startx;
		wid++;
	}
}

void	draw_map(t_display *display, char **map, char player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] != 'n' && map[y][x])
		{
			draw_square(display, x * 65, y * 65, 64, WHITE);
			if (map[y][x] == player)
				draw_square(display, x * 65 + 28, y * 65 + 28, 10, ORANGE);
			x++;
		}
		x = 0;
		y++;
	}
}

void	signle_cast()
{
	int	x;
	int	y;

	while (map[x][y]
}

int	main(int ac, char **av)
{
	t_data		data;
	t_display	display;

	check_args(ac, av);
	ft_bzero(&data, sizeof(t_data *));
	ft_bzero(&display, sizeof(t_display *));
	if (!dump(av[1], &data) || !init_display(&display))
		ft_kill(&display, &data, EXIT_FAILURE);
	draw_map(&display, data.map, data.player_dir);
	mlx_loop(display.main);
	kill_display(&display);
	delete_data(&data);
	return (EXIT_SUCCESS);
}
