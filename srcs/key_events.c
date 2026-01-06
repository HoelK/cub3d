#include "cub3d.h"

#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363
#define KEY_ESC		65307

#define KPRESS		2
#define KRELEASE	3
#define BPRESS		4
#define BRELEASE	5
#define MOTION		6
#define DESTROY		17

#define KPRESSMASK	(1L<<0)
#define KRELMASK	(1L<<1)
#define BPRESSMASK	(1L<<2)
#define PMOTIONMASK (1L<<6)

void	hooks(t_game *game)
{
	mlx_hook(game->display.window, DESTROY, 1L<<2, close_game, game);
	mlx_loop(game->display.main);
}
