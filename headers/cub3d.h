/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/18 03:33:11 by hkeromne         ###   ########.fr       */
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
# define MAP_BUFFER 10
# define MAP_SET " 01NSEW"
# define SPACE_CHARS " \t\n\v\f\r"

enum e_arg_errors
{
	TOO_MANY_ARGS,
	TOO_LITT_ARGS,
	INVALID_PATH,
	INVALID_FORMAT
};

enum e_err_mode
{
	MISSING,
	DUPLICATE,
	INVALID
};

enum e_err_obj
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	MAP,
	PLAYER,
	TEXTURE,
	SYNTAX,
	COLOR,
	LINK,
	ID
};

enum e_err_sys
{
	MALLOC
};

enum e_rgb_data
{
	LEN,
	FIELD_LEN,
	FIELD_VALUE,
	FIELD_COUNT
};

enum e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
};

enum e_ydirections
{
	FLOOR,
	CEIL
};

enum e_colors
{
	R,
	G,
	B
};

typedef struct s_data
{
	char		**map;
	uint32_t	map_size;
	uint8_t		colors[2][3];
	char		*texture_path[4];
	uint32_t	player_x;
	uint32_t	player_y;
}	t_data;

//CUB Interpreter
t_data	*parse(char	*path_file, t_data *data);
int		dump(char *file_path, t_data *data);
int8_t	check_id(const char *id, size_t line, bool check_mod);
bool	check_link(const char *link, size_t line, t_data *data, int8_t id);
bool	check_color(const char *color, size_t line, t_data *data, int8_t id);
void	parse_error(uint8_t mode, uint8_t error, size_t line);
void	system_error(uint8_t error);
bool	check_map(int fd, char *line, size_t line_n, t_data *data);
void	delete_data(t_data *data);
bool	init_data(t_data *data);

//Arg check
void	check_path(char *path);
void	check_args(int ac, char **av);

//Error Management
void	write_error(uint8_t error);
void	ft_exit(ssize_t	error);

#endif
