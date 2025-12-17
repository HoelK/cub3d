/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:20:29 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/14 01:58:07 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_BUFFER 10

bool	check_line(char *line, size_t line_n)
{
	uint32_t	i;

	i = 0;
	while (line[i++])
	{
		if (!ft_isset(line[i], MAP_SET))
			parse_error(INVALID, MAP, line_n);
	}
}

bool	check_map(int fd, char *line, size_t line_n, t_data *data)
{
	bool		ret;
	char		**map;
	uint32_t	buffer;

	ret = true;
	buffer = MAP_BUFFER;
	map = malloc(sizeof(char **) * buffer);
	if (!map)
		return (system_error(MALLOC), false);
	while (*line)
	{
		if (!check_line(line, line_n++))
			ret = false;
		line = get_next_line(fd);
	}
}
