/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:40 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/12 06:09:51 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SPACE_CHARS " \t\n\v\f\r"

#include "cub3d.h"

/*void	parse_exit(char	**file)
{
	ft_double_free(file);
	exit (EXIT_FAILURE);
}

bool	check_line(const char *to_check, const char *to_find)
{
	size_t	i;

	i = 0;
	if (!to_check || !*to_check || !to_check || !*to_check)
		return (false);
	while (ft_isspace(to_check[i]))
		i++;
	return (!ft_strcmp(&to_check[i], to_find));
}

bool	empty_line(const char *line)
{
	if (!line || !*line)
		return (false);
	while (ft_isspace(*line))
		line++;
	return (!*line || *line == '\n');
}

void	skip_empty(const char **file, size_t *line, size_t *col)
{
		while (empty_line(file[*line]))
			*line++;
		if (!file[*line])
			return ;
		while (ft_isspace(file[*line][*col]))
			*col++;
}

void	check_rest(const char *line, size_t line, uint8_t id)
{
	while (!ft_isspace(line))
		line++;
	if (!*line)
		return (parse_error(MISSING, id, line));
	while (ft_isline(*line))
		line++;
}

void	check_id(const char *id, size_t line, bool missing)
{
	size_t	i;
	static bool	dirs[6] = {true};
	const char	*dirs_s[6];

	i = 0;
	dirs_s[0] = "NO";
	dirs_s[1] = "SO";
	dirs_s[2] = "WE";
	dirs_s[3] = "EA";
	dirs_s[4] = "F";
	dirs_s[5] = "L";
	if (missing)
		return (check_missing(dirs))
	if (!id || !*id)
		return ;
	while (i < 6 && ft_strncmp(dirs_s[i], file, ft_strlen(dir_s[i]))
		i++;
	if (i == 6)
		return (parse_error(INVALID, ID, line), );
	else if (dirs[i] == false)
		return (parse_error(DUPLICATE, i, line), );
	else
		dirs[i] = false;
	return (check_rest(id, line));
}

void	check_missing(bool *dirs)
{
	uint8_t	i;

	i = 0;
	while (i < 4)
	{
		if (dirs[i] == true)
			parse_error(MISSING, i, i);
		i++;
	}
}

bool	check_file(char **file)
{
	size_t	col;
	size_t	line;
	bool	ret;
	
	col = 0;
	line = 0;
	ret = false;
	if (ft_doublelen(file) < 9)
		return (false);
	while (file[line])
	{
		skip_empty(file, &line, &col);
		check_id(&file[line][col], line, false);
		col = 0;
		line++;
	}
	check_id(&file[line][col], line, true);
	return (true);
}

t_data	*get_data()
{
	get_textures();
	get_colors();
	get_map();
}

bool	check_data()
{
}

void	test_error(void)
{
	parse_error(INVALID, SYNTAX, 2);
	parse_error(INVALID, ID, 2);
	parse_error(INVALID, MAP, 2);
	parse_error(DUPLICATE, FLOOR, 2);
	parse_error(DUPLICATE, CEIL, 2);
	parse_error(DUPLICATE, NORTH, 2);
	parse_error(DUPLICATE, SOUTH, 2);
	parse_error(DUPLICATE, WEST, 2);
	parse_error(DUPLICATE, EAST, 2);
	parse_error(MISSING, NORTH, 2);
	parse_error(MISSING, SOUTH, 2);
	parse_error(MISSING, EAST, 2);
	parse_error(MISSING, WEST, 2);
	parse_error(MISSING, MAP, 2);
}*/
void	ft_triple_write(char ***file)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (file[i])
	{
		while (file[i][j])
		{
			ft_putstr_fd(file[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	ft_triple_free(char ***strs)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
			free(strs[i][j++]);
		j = 0;
		free(strs[i++]);
	}
	free(strs);
}

t_data	*parse(char	*file_path, t_data *data)
{
	char	***file;

	file = dump(file_path);
	if (file == NULL)
		exit(EXIT_FAILURE);
	//if (!check_file(file))
	//	return (NULL);
	ft_triple_write(file);
	ft_triple_free(file);
	return (data);
}
