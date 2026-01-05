/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/19 04:20:57 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../srcs/cub_interpreter/cub_interpreter.h"
# include "../minilibx-linux/mlx.h"
# define RES_X 1280
# define RES_Y 720
# define NO_RESIZE false

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_display
{
	void	*main;
	void	*window;
	t_img	frame;
}	t_display;

enum e_arg_errors
{
	TOO_MANY_ARGS,
	TOO_LITT_ARGS,
	INVALID_PATH,
	INVALID_FORMAT
};

//Arg check
void	check_path(char *path);
void	check_args(int ac, char **av);

//Error Management
void	write_error(uint8_t error);
void	ft_exit(ssize_t	error);

#endif
