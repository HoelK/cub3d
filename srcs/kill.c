/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:30:35 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/10 17:30:36 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_kill(t_game *game, uint8_t status)
{
	delete_data(&game->data);
	kill_display(&game->display);
	exit (status);
}

int	close_game(t_game *game)
{
	ft_kill((t_game *)game, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
