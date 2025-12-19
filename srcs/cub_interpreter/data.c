/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:29:48 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/19 01:29:27 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

void	init_data(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	data->map = NULL;
	while (i < 4)
		data->texture_path[i++] = NULL;
	i = 0;
	while (i < 2)
	{
		while (j < 3)
			data->colors[i][j++] = 0;
		j = 0;
		i++;
	}
}

void	delete_data(t_data *data)
{
	uint8_t	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	i = 0;
	while (i < 4)
	{
		if (data->texture_path[i])
			free(data->texture_path[i]);
		i++;
	}
}
