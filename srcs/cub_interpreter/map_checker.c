/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:36:42 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/19 01:15:33 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

bool	check_player(char c, size_t line_n)
{
	static bool	player = false;

	if (ft_isset(c, PLAYER_SET))
	{
		if (player)
			return (parse_error(DUPLICATE, PLAYER, line_n), false);
		player = true;
	}
	return (true);
}

bool	check_map_line(char *line, size_t line_n)
{
	uint32_t		i;
	bool			ret;

	i = 0;
	ret = true;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_isset(line[i], MAP_SET) || !check_player(line[i], line_n))
		{
			parse_error(INVALID, MAP, line_n);
			ret = false;
		}
		i++;
	}
	return (ret);
}

bool	flood_fill(char **map, int x, int y, bool *closed)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y]
		|| map[x][y] == '\n' || map[x][y] == ' ')
	{
		if (*closed)
			parse_error(INVALID, MAP, x + 1);
		*closed = false;
		return (closed);
	}
	else if (map[x][y] == '1' || map[x][y] == 'x')
		return (true);
	map[x][y] = 'x';
	flood_fill(map, x + 1, y, closed);
	flood_fill(map, x - 1, y, closed);
	flood_fill(map, x, y + 1, closed);
	flood_fill(map, x, y - 1, closed);
	return (*closed);
}

bool	find_player(t_data *data)
{
	ssize_t	x;
	ssize_t	y;

	x = -1;
	y = -1;
	while (data->map[++x])
	{
		while (data->map[x][++y])
		{
			if (ft_isset(data->map[x][y], PLAYER_SET))
			{
				data->player_x = x;
				data->player_y = y;
				return (true);
			}
		}
		y = 0;
	}
	return (parse_error(MISSING, PLAYER, 0), false);
}
