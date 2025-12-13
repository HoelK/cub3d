/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/13 01:47:24 by hkeromne         ###   ########.fr       */
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

enum e_err_id
{
	TEXTURE,
	SYNTAX,
	COLOR,
	LINK,
	MAP,
	ID
};

enum e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	F,
	C
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
	char		*texture_path[4];
	uint8_t		colors[2][3];
	char		**map;
}	t_data;

//CUB Interpreter
int	dump(char *file_path, t_data *data);
t_data	*parse(char	*path_file, t_data *data);
void	parse_error(uint8_t mode, uint8_t error, size_t line);

//Arg check
void	check_path(char *path);
void	check_args(int ac, char **av);

//Parse
char	**ft_double_realloc(char **old, size_t old_ptr_n, size_t new_ptr_n);
bool	check_paths(char *texture_path);
bool	check_colors(uint8_t **colors);
bool	check_map(char	**map);
ssize_t	count_lines(const char *file_path);

//Error Management
void	write_error(uint8_t error);
void	ft_exit(ssize_t	error);

#endif
