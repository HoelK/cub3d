/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:20:29 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/18 04:48:37 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PLAYER_SET "NEWS"

bool	alloc_map(t_data *data)
{
	uint32_t	i;

	i = 0;
	data->map_size = MAP_BUFFER;
	data->map = malloc(sizeof(char **) * (data->map_size + 1));
	if (!data->map)
		return (system_error(MALLOC), false);
	while (i < data->map_size)
		data->map[i++] = NULL;
	return (true);
}

bool	add_line(char *line, t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->map_size && data->map[i])
		i++;
	if (i < data->map_size)
		data->map[i] = line;
	else
	{
		data->map = ft_double_realloc(data->map, data->map_size,
				data->map_size * 2);
		if (!data->map)
			return (system_error(MALLOC), false);
		data->map[i] = line;
		data->map_size *= 2;
	}
	return (true);
}

bool	check_player(char c, size_t line_n)
{
	static bool	player = false;

	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (player)
			return (parse_error(DUPLICATE, PLAYER, line_n), false);
		player = true;
	}
	return (true);
}

bool	check_line(char *line, size_t line_n)
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
		{
			*closed = false;
			parse_error(INVALID, MAP, x + 1);
		}
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
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		while (data->map[x][y])
		{
			if (ft_isset(data->map[x][y], PLAYER_SET))
			{
				data->player_x = x;
				data->player_y = y;
				return (true);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (parse_error(MISSING, PLAYER, 0), false);
}

bool	check_map(int fd, char *line, size_t line_n, t_data *data)
{
	bool		ret;
	bool		valid;

	ret = true;
	valid = true;
	if (!alloc_map(data))
		return (false);
	while (line)
	{
		if (!check_line(line, line_n++))
			(free(line), ret = false);
		else
			add_line(line, data);
		line = get_next_line(fd);
	}
	if (!ret || !find_player(data)
		|| !flood_fill(data->map, data->player_x, data->player_y, &valid))
		return (delete_data(data), false);
	return (true);
}
