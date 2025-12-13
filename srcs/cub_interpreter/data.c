/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:29:48 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/13 01:29:50 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_data(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	if (data->map)
		free(data->map);
	while (i < 4)
	{
		if (data->texture[i])
			free(data->texture[i]);
		i++;
	}
}

bool	init_data(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	data->map = NULL;
	while (i < 4)
		data->texure_path[i++] = NULL;
	i = 0;
	while (i < 2)
	{
		while (j < 3)
			data->colors[i][j++] = 0;
		j = 0;
		i++;
	}
}
