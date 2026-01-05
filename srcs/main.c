/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:35 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/05 19:54:25 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_player	player;
	t_display	display;

	check_args(ac, av);
	ft_bzero(&data, sizeof(t_data *));
	ft_bzero(&display, sizeof(t_display *));
	if (!dump(av[1], &data) || !init_display(&display))
		ft_kill(&display, &data, EXIT_FAILURE);

	player.pos = get_point(data.player_x, data.player_y);
	draw_map(&display, data.map, player.pos);
	raycast(&display, player.pos);

	mlx_put_image_to_window(display.main, display.window, display.frame.img, 0, 0);
	mlx_loop(display.main);
	kill_display(&display);
	delete_data(&data);
	return (EXIT_SUCCESS);
}
