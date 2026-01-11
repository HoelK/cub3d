/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:45 by hkeromne          #+#    #+#             */
/*   Updated: 2026/01/11 16:39:51 by hkeromne         ###   ########.fr       */
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
# define RES_X			1920
# define RES_Y			1080
# define NO_RESIZE		false
# define FOV			90
# define PI				3.141592
# define MOVE_SPEED		0.1
# define ROTATE_SPEED	0.0872

# define WHITE			0xFFFFFF
# define ORANGE			0xFFA500
# define GREY			0x808080

# define TIDLE_SIZE		10
# define PLAYER_SIZE	2

# define KEY_AMOUNT		7
# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define MCLICK_L		1

# define KPRESS			2
# define KREL			3
# define BPRESS			4
# define MOTION			6
# define DESTROY		17

# define KPRESSMASK		1
# define KRELMASK		2
# define BPRESSMASK		4
# define PMOTIONMASK	64

# define FRAME_AMOUNT	10
# define SPRITE_PATH	"./sprites/"

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	pos;
	t_point	dir;
	t_point	cplane;
	float	angle;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_img;

typedef struct s_sprite
{
	int		current_frame;
	t_img	frames[FRAME_AMOUNT];
}	t_sprite;


typedef struct s_tex
{
	int		id;
	int		x;
	int		y;
	int		color;
	double	step;
	double	pos;
}	t_tex;

typedef struct s_display
{
	void	*main;
	void	*window;
	t_img	frame;
	t_img	minimap;
	t_img	texture[4];
	t_sprite	sprite;
}	t_display;

typedef struct s_ddata
{
	bool	side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	t_point	delta;
	t_point	hit_pos;
	t_point	side_dist;
	float	wall_dist;
	float	wall_x;
}	t_ddata;

typedef struct s_ray
{
	t_point	dir;
	int		id;
	int		line_start;
	int		line_end;
	int		line_len;
}	t_ray;

typedef struct s_game
{
	uint32_t	time;
	t_ddata		dda;
	t_data		data;
	t_player	player;
	t_display	display;
	bool		keys[KEY_AMOUNT];
}	t_game;

enum e_arg_errors
{
	TOO_MANY_ARGS,
	TOO_LITT_ARGS,
	INVALID_PATH,
	INVALID_FORMAT,
	INVALID_RES
};

enum e_key_ids
{
	KW_ID,
	KA_ID,
	KS_ID,
	KD_ID,
	KLEFT_ID,
	KRIGHT_ID,
	MCLICKL_ID
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
void		my_mlx_pixel_put(t_img *data, t_point px, int color);
void		draw_ceil(t_img *frame, int color);
void		draw_floor(t_img *frame, int color);
void		draw_line(t_img *img, t_point start, t_point end, int color);
void		draw_square(t_img *img, t_point start, int size, int color);

//DDA
t_point		get_delta(t_point dir);
t_ddata		dda(t_point player, char **map, t_ray *ray);
float		get_wallx(t_ddata *dda, t_point dir, t_point player);
float		get_walldist(t_ddata *dda, t_point player, t_point dir);

//Raycast
void		raycast(t_game *game);

//Minimap
t_point		normalize_tidle(t_point px);
t_point		normalize_player(t_point px);
void		draw_map(t_display *display, char **map, t_point player);
void		img_to_frame(t_img *frame, t_img *img, int height, int width, int place_x, int place_y);

//Display management
bool		init_display(t_display *display, t_data *data);
void		kill_display(t_display *display);
void		ft_kill(t_game *game, uint8_t status);
int			close_game(t_game *game);

//Key events
void		hooks(t_game *game);
int			render(t_game *game);
int			handle_input(t_game *game);

//Movements
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_forward(t_game *game);
void		move_backward(t_game *game);

//Mouse
void		turn_right(t_game *game, int diff, bool mouse);
void		turn_left(t_game *game, int diff, bool mouse);

//Init
void		game_init(char *file, t_game *game);

//Renderer
int			render(t_game *game);
uint32_t	get_time(void);

//Utils
int			rgb_to_hex(uint8_t *rgb);
float		angle_to_radian(int angle);

//Sprites
void		update_frame(t_game *game);
bool		init_sprite(t_display *display);
void		destroy_sprites(t_display *display);

#endif
