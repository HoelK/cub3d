/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 05:52:27 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/12 06:37:49 by hkeromne         ###   ########.fr       */
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

char	***remove_spaces(char **file)
{
	ssize_t	i;
	char	***res;

	i = -1;
	res = malloc(sizeof(char **) * (ft_doublelen(file) + 1));
	if (!res)
		return (NULL);
	while (file[++i] && !map_detected(file[i]))
		res[i] = ft_split(file[i], SPACE_CHARS);
	res[i] = NULL;
	ft_double_free(file);
	return (res);
}

char	***dump(char *file_path)
{
	char	***file;
	char	**raw_file;

	file = NULL;
	raw_file = ft_dump_file(file_path);
	if (!raw_file)
		return (NULL);
	file = remove_spaces(raw_file);
	return (file);
}
