#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

enum e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

enum e_colors
{
	FLOOR,
	CEIL,
	R,
	G,
	B
};

typedef struct s_map
{
	char		texture_path[4];
	uint8_t		colors[2][3];
	char		**map;
}	t_map;

//Arg
bool	check_args(int ac, char **av);

//Parse
char	**dump_file(char *file_path);
bool	check_paths(char *texture_path);
bool	check_colors(uint8_t **colors);
bool	check_map(char	**map);

#endif
