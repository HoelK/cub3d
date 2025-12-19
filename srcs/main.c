/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:35 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/19 04:43:12 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_display(t_display *display);
void	kill_display(t_display *display);
void	ft_kill(t_display *display, t_data *data, uint8_t status);

int	main(int ac, char **av)
{
	t_data		data;
	t_display	display;

	check_args(ac, av);
	ft_bzero(&data, sizeof(t_data *));
	ft_bzero(&display, sizeof(t_display *));
	if (!dump(av[1], &data) || !init_display(&display))
		ft_kill(&display, &data, EXIT_FAILURE);
	kill_display(&display);
	delete_data(&data);
	return (EXIT_SUCCESS);
}
