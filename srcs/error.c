/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:58:39 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 16:41:24 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	write_usage(void)
{
	write(2, "Usage : ./cub3d <map.cub>\n", 26);
}

void	write_error(uint8_t error)
{
	write(2, "cub3d: ", 7);
	if (error == TOO_MANY_ARGS)
		(write(2, "Too Many Arguments\n", 19), write_usage());
	else if (error == TOO_LITT_ARGS)
		(write(2, "Not Enough Arguments\n", 21), write_usage());
	else if (error == INVALID_FORMAT)
		write(2, "Invalid Format, Map must be .cub\n", 33);
	else if (error == INVALID_PATH)
		write(2, "File does not exist or Missing Permissions\n", 43);
	else if (error == INVALID_RES)
		write(2, "Supported resolutions : 1920x1080\n", 35);
}

void	ft_exit(ssize_t	error)
{
	if (error >= 0)
		(write_error(error), exit(EXIT_FAILURE));
	exit(EXIT_SUCCESS);
}
