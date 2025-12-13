/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:52:27 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/13 06:20:16 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_SET "01NSEW"
#define SPACE_CHARS " \t\n\v\f\r"
#define NUM_CHARS "0123456789"

bool	map_detected(const char *line)
{
	if (!line || !*line || *line == '\n')
		return (false);
	while (*line && ft_isset(*line, MAP_SET))
		line++;
	return (*line == '\n' || !*line);
}

int8_t	check_id(const char *id, size_t line)
{
	size_t	i;
	static bool	dirs[6] = { true, true, true, true, true, true };
	const char	*dirs_s[6];

	i = 0;
	dirs_s[0] = "NO";
	dirs_s[1] = "SO";
	dirs_s[2] = "WE";
	dirs_s[3] = "EA";
	dirs_s[4] = "F";
	dirs_s[5] = "L";
	if (!id || !*id)
		return (-1);
	while (i < 6 && ft_strncmp(dirs_s[i], id, ft_strlen(dirs_s[i])))
		i++;
	if (i == 6)
		return (parse_error(INVALID, ID, line), -1);
	if (dirs[i] == false)
		return (parse_error(DUPLICATE, i, line), -1);
	dirs[i] = false;
	return (i);
}

bool	check_link(const char *link, size_t line, t_data *data, int8_t id)
{
	int	fd;

	fd = open(link, O_RDONLY);
	if (fd == -1)
		return (parse_error(INVALID, LINK, line), false);
	close (fd);
	data->texture_path[id] = ft_strdup(link);
	return (true);
}

size_t	ft_len_to(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}


ssize_t	get_color(const char *color)
{
	int	result;

	result = 0;
	if (ft_len_to(color, ',') > 3)
		return (-1);
	while (*color && ft_isdigit(*color))
	{
		result += *color - '0';
		if (ft_isdigit(*(color + 1)))
			result *= 10;
		color++;
	}
	if (result >= 0 && result <= 255)
		return (result);
	return (-1);
}

bool	check_rgb_format(const char *color)
{
	uint8_t		commas;
	uint8_t		field_width;
	uint32_t	field_value;
	uint8_t		field_amount;

	commas = 0;
	field_width = 0;
	field_value = 0;
	field_amount = 0;
	if (ft_strlen(color) < 5 || ft_strlen(color) > ((3 * 3) + 2))
		return (false);
	while (*color && (ft_isdigit(*color) || *color == ','))
	{
		//check_field
		if (ft_isdigit(*color))
			field_amount++;
		while ((*color && ft_isdigit(*color)) && (field_width < 4 && field_value < 256))
		{
			field_width++;
			field_value += *color - '0';
			if (ft_isdigit(*(color + 1)))
				field_value *= 10;
			color++;
		}
		if (field_width == 0 || field_width == 4 || field_value > 255)
			return (false);
		//check_commas
		if (*color == ',')
			(commas++, color++);
		if (commas > 3 || *color == ',')
			return (false);
		field_width = 0;
		field_value = 0;
	}
	if (field_amount != 3)
		return (false);
	return (true);
}

void	check_color(const char *color, size_t line, t_data *data, int8_t id)
{
	size_t	i;
	size_t	j;
	uint8_t	v_count;
	int		i_color;

	i = 0;
	j = 0;
	v_count = 0;
	if (ft_strlen(color) < 5 || ft_strlen(color) > ((3 * 3) + 2))
		return (parse_error(INVALID, COLOR, line));
	while (*color && ft_isset(*color, ","NUM_CHARS) && i < 3)
	{
		i_color = get_color(color);
		if (i_color == -1)
			return (parse_error(INVALID, COLOR, line));
		data->colors[id][i] = i_color;
		while (*color && *color != ',')
			color++;
		if (*color && *color == ',')
			(color++, v_count++);
		if (v_count > 2 || *color == ',')
			return (parse_error(INVALID, COLOR, line));
	}
}

void	check_tokens(char *line, size_t line_n, t_data *data)
{
	int8_t	id;
	char	*token;

	token = ft_strtok(line, SPACE_CHARS);
	if (token == NULL)
		return ;
	id = check_id(token, line_n);
	token = ft_strtok(NULL, SPACE_CHARS);
	if (id >= 0 && id < 4)
		check_link(token, line_n, data, id);
	else if (id >= 0)
	{
		if (!check_rgb_format(token))
			return (parse_error(INVALID, COLOR, line_n));
	}
	token = ft_strtok(NULL, SPACE_CHARS);
	if (token)
		return (parse_error(INVALID, SYNTAX, line_n), free(line));
}

int	dump(char *file_path, t_data *data)
{
	int		fd;
	char	*line;
	size_t	line_n;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line_n = 1;
	line = get_next_line(fd);
	while (line && !map_detected(line))
	{
		check_tokens(line, line_n++, data);
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
	//check_map(fd, data);
}
