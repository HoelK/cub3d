/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:52:27 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/14 00:57:02 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_SET "01NSEW"
#define SPACE_CHARS " \t\n\v\f\r"

bool	map_detected(const char *line)
{
	if (!line || !*line || *line == '\n')
		return (false);
	while (*line && ft_isset(*line, MAP_SET))
		line++;
	return (*line == '\n' || !*line);
}

bool	check_syntax(size_t line_n)
{
	if (ft_strtok(NULL, SPACE_CHARS))
		return (parse_error(INVALID, SYNTAX, line_n), false);
	return (true);
}

bool	check_tokens(char *line, size_t line_n, t_data *data)
{
	int8_t	id;
	bool	ret;
	char	*token;

	token = ft_strtok(line, SPACE_CHARS);
	id = check_id(token, line_n, false);
	token = ft_strtok(NULL, SPACE_CHARS);
	if (id < 4)
		ret = check_link(token, line_n, data, id);
	else 
		ret = check_color(token, line_n, data, id);
	if (!check_syntax(line_n))
		ret = false;
	return (ret);
}

int	dump(char *file_path, t_data *data)
{
	int		fd;
	bool	ret;
	char	*line;
	size_t	line_n;

	ret = true;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line_n = 1;
	line = get_next_line(fd);
	while (line && !map_detected(line))
	{
		if (!check_tokens(line, line_n++, data))
			ret = false;
		free(line);
		line = get_next_line(fd);
	}
	check_id(NULL, 0, true);
	//check_map(fd, data);
	return (ret);
}
