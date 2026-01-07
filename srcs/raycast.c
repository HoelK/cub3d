/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:38:26 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/07 21:38:50 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_display *display, t_point player, t_point dir)
{
	t_point	end;

	end.x = (player.x + dir.x);
	end.y = (player.y + dir.y);
	draw_line(display, normalize_player(player), normalize_player(end), ORANGE);
}
