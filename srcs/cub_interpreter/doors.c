/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:56:49 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 21:21:01 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "cub3d.h"

void	update_door(t_game *game)
{
	int	door_x;
	int	door_y;

	door_x = (int)(game->player.pos.x + game->player.dir.x * 1.5);
	door_y = (int)(game->player.pos.y + game->player.dir.y * 1.5);
	if (is_door(game->data.map, door_x, door_y)
		|| game->data.map[door_y][door_x] == 'd')
	{
		if (game->data.map[door_y][door_x] == 'D')
			game->data.map[door_y][door_x] = 'd';
		else
			game->data.map[door_y][door_x] = 'D';
	}
	game->keys[KF_ID] = false;
}

bool	is_door(char **map, int x, int y)
{
	return (map[y][x] == 'D');
}

void	replace_doors(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->door_curr)
		data->map[data->doors[i].y][data->doors[i].x] = 'D';
}

void	add_door(t_data *data, int x, int y)
{
	if (data->door_curr + 1 == data->door_tot)
	{
		data->doors = ft_realloc(data->doors,
				sizeof(t_door) * data->door_tot,
				(sizeof(t_door) * data->door_tot) * 2);
		data->door_tot *= 2;
	}
	data->doors[data->door_curr].x = x;
	data->doors[data->door_curr].y = y;
	data->doors[data->door_curr].open = false;
	data->doors[data->door_curr].destroyed = false;
	data->door_curr++;
}
