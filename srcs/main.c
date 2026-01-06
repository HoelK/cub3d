/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:35 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/06 20:41:51 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	draw_map(&game->display, game->data.map, game->player.pos);
	raycast(&game->display, game->player.pos, game->player.dir);
	mlx_put_image_to_window(game->display.main, game->display.window, game->display.frame.img, 0, 0);
	return (EXIT_SUCCESS);
}


void	player_init(t_game *game, t_point data)
{
	game->player.pos.x = data.x;
	game->player.pos.y = data.y;
	game->player.angle = ;
	game->player.dir.x = cos
}

void	game_init(char *file, t_game *game)
{
	ft_bzero(game, sizeof(t_game *));
	if (!dump(file, &game->data) || !init_display(&game->display))
		ft_kill(game, EXIT_FAILURE);
	player_init(game, get_point(game->data.player_x, game->data.player_y));
}

int	main(int ac, char **av)
{
	t_game		game;

	check_args(ac, av);
	game_init(av[1], &game);
	hooks(&game);
	return (EXIT_SUCCESS);
}
