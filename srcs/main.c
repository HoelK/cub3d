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

bool	init_display(t_display *display);
void	my_mlx_pixel_put(t_img *frame, int x, int y, int color);
void	kill_display(t_display *display);
void	ft_kill(t_display *display, t_data *data, uint8_t status);
void	put_buffer_line(t_display *display, int x, int y_start);

int	raycast(t_data *data, t_display *display)
{
	long	ray_x;
	long	ray_y;
	long	ray_z;

	ray_x = data->player_x;
	ray_y = data->player_y;
	while (data->map[ray_y][ray_x] != '1')
		ray_x++;
	if ((ray_x - data->player_x) < 3)
		ray_x += 3;
	ray_z = RES_Y / (ray_x - data->player_x);
	put_buffer_line(display, RES_X / 2, ray_z);
	return (true);
}

void	put_buffer_line(t_display *display, int x, int y_start, int color)
{
	int	y_end;

	y_end = RES_Y - y_start;
	while (y_start < y_end)
		my_mlx_pixel_put(&display->frame, x, y_start++, color);
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
	raycast(&data, &display);
	mlx_loop(display.main);
	kill_display(&display);
	delete_data(&data);
	return (EXIT_SUCCESS);
}
