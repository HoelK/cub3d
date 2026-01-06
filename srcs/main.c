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
	t_game		game;

	check_args(ac, av);
	ft_bzero(&game, sizeof(t_game *));
	if (!dump(av[1], &game.data) || !init_display(&game.display))
		ft_kill(&game, EXIT_FAILURE);

	game.player.pos = get_point(game.data.player_x, game.data.player_y);
	draw_map(&game.display, game.data.map, game.player.pos);
	raycast(&game.display, game.player.pos);

	mlx_put_image_to_window(game.display.main, game.display.window, game.display.frame.img, 0, 0);
	hooks(&game);
	mlx_loop(game.display.main);
	return (EXIT_SUCCESS);
}
