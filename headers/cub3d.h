/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/06 20:35:53 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../srcs/cub_interpreter/cub_interpreter.h"
# include "../minilibx-linux/mlx.h"
# define RES_X 1280
# define RES_Y 720
# define NO_RESIZE false
# define FOV 90

# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define GREY 0x808080

# define TIDLE_SIZE 64
# define PLAYER_SIZE 2

#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363
#define KEY_ESC		65307

#define KPRESS		2
#define BPRESS		4
#define MOTION		6
#define DESTROY		17

#define KPRESSMASK	(1L<<0)
#define BPRESSMASK	(1L<<2)
#define PMOTIONMASK (1L<<6)

typedef struct	s_point
{
	double	x;
	double	y;
} t_point;

typedef struct s_player
{
	t_point pos;
	float	angle;
	t_point	dir;
	t_point	cam_plane;
}	t_player;

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

typedef struct s_game
{
	t_data		data;
	t_display	display;
	t_player	player;
}	t_game;

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

//Points
t_point	get_point(float x, float y);
void	print_point(t_point vec, const char *name);
t_point rotate_point_around(t_point center, t_point point, double angle);

//Draw
void	draw_line(t_display *disp, t_point start, t_point end, int color);
void	draw_square(t_display *display, t_point start, int size, int color);

//Raycast
void raycast(t_display *display, t_point player, t_point dir);

//Minimap
t_point	normalize_tidle(t_point px);
t_point	normalize_player(t_point px);
void	draw_map(t_display *display, char **map, t_point player);

//Display management
bool	init_display(t_display *display);
void	kill_display(t_display *display);
void	my_mlx_pixel_put(t_img *data, t_point px, int color);
void	ft_kill(t_game *game, uint8_t status);
int		close_game(t_game *game);

//Key events
void	hooks(t_game *game);
int	render(t_game *game);

#endif
