/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_interpreter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <student@42lehavre.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:02:19 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/19 02:02:20 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_INTERPRETER_H
# define CUB_INTERPRETER_H

typedef struct s_data
{
	char		**map;
	uint32_t	map_size;
	uint8_t		colors[2][3];
	char		*texture_path[4];
	char		player_dir;
	uint32_t	player_x;
	uint32_t	player_y;
}	t_data;

enum e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST
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

//Process whole file
int		dump(char *file_path, t_data *data);

//Data structure
void	init_data(t_data *data);
void	delete_data(t_data *data);

#endif
