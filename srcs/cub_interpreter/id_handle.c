/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:06:15 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/18 04:45:57 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_missing(bool *dirs)
{
	uint8_t	i;

	i = 0;
	while (i < 6)
	{
		if (dirs[i])
			parse_error(MISSING, i, 0);
		i++;
	}
}

int8_t	check_id(const char *id, size_t line, bool check_mod)
{
	size_t		i;
	static bool	dirs[6] = {true, true, true, true, true, true};
	const char	*dirs_s[6];

	i = 0;
	dirs_s[0] = "NO";
	dirs_s[1] = "SO";
	dirs_s[2] = "WE";
	dirs_s[3] = "EA";
	dirs_s[4] = "F";
	dirs_s[5] = "C";
	if (check_mod)
		return (check_missing(dirs), -1);
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
