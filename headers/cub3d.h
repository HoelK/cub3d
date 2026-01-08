/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/08 03:00:35 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "../srcs/cub_interpreter/cub_interpreter.h"
# define RES_X 1280
# define RES_Y 720
# define NO_RESIZE false
# define FOV 90
# define PI 3.141592
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.0872

# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define GREY 0x808080

# define TIDLE_SIZE 64
# define PLAYER_SIZE 2

# define KEY_AMOUNT	4
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307

# define KPRESS		2
# define KREL		3
# define BPRESS		4
# define MOTION		6
# define DESTROY		17

# define KPRESSMASK	(1L<<0)
# define KRELMASK	(1L<<1)
# define BPRESSMASK	(1L<<2)
# define PMOTIONMASK (1L<<6)

typedef struct	s_point
{
	double	x;
	double	y;
} t_point;

typedef struct s_player
{
	t_point	pos;
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

typedef struct s_ddata
{
	bool	side;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	t_point	delta;
	t_point	hit_pos;
	t_point	side_dist;
	float	perpWallDist;
}	t_ddata;

typedef struct s_game
{
	t_data		data;
	t_ddata		dda;
	t_player	player;
	t_display	display;
	bool		keys[KEY_AMOUNT];
	uint32_t	time;
}	t_game;

enum e_arg_errors
{
	TOO_MANY_ARGS,
	TOO_LITT_ARGS,
	INVALID_PATH,
	INVALID_FORMAT
};

enum e_key_ids
{
	KUP_ID,
	KDOWN_ID,
	KLEFT_ID,
	KRIGHT_ID
};

//Arg check
void		check_path(char *path);
void		check_args(int ac, char **av);

//Error Management
void		write_error(uint8_t error);
void		ft_exit(ssize_t	error);

//Points
t_point		get_point(float x, float y);
void		print_point(t_point vec, const char *name);
t_point		rotate_point_around(t_point center, t_point point, double angle);

//Draw
void		draw_line(t_display *disp, t_point start, t_point end, int color);
void		draw_square(t_display *display, t_point start, int size, int color);

//DDA
t_ddata	dda(t_point player, t_point dir, char **map);

//Raycast
void		raycast(t_game *game);

//Minimap
t_point		normalize_tidle(t_point px);
t_point		normalize_player(t_point px);
void		draw_map(t_display *display, char **map, t_point player);

//Display management
bool		init_display(t_display *display);
void		kill_display(t_display *display);
void		my_mlx_pixel_put(t_img *data, t_point px, int color);
void		ft_kill(t_game *game, uint8_t status);
int			close_game(t_game *game);

//Key events
void		hooks(t_game *game);
int			render(t_game *game);
int			handle_input(t_game *game);

//Movements
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);

//Init
void		game_init(char *file, t_game *game);

//Renderer
int			render(t_game *game);
uint32_t	get_time(void);

#endif
