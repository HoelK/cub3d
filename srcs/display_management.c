#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, t_point px, int color)
{
	char	*dst;

	dst = data->addr + ((int)px.y * data->line_length + (int)px.x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

bool	init_display(t_display *display)
{
	display->main = mlx_init();
	if (!display->main)
		return (false);
	display->window = mlx_new_window(display->main, RES_X, RES_Y, "cub3d");
	if (!display->window)
		return (false);
	display->frame.img = mlx_new_image(display->main, RES_X, RES_Y);
	if (!display->frame.img)
		return (false);
	display->frame.addr = mlx_get_data_addr(display->frame.img, &display->frame.bits_per_pixel, &display->frame.line_length,
			&display->frame.endian);
	if (!display->frame.addr)
		return (false);
	return (true);
}

void	kill_display(t_display *display)
{
	if (display->frame.img)
		mlx_destroy_image(display->main, display->frame.img);
	if (display->window)
		mlx_destroy_window(display->main, display->window);
	if (display->main)
		mlx_destroy_display(display->main);
	free(display->main);
}

void	ft_kill(t_display *display, t_data *data, uint8_t status)
{
	delete_data(data);
	kill_display(display);
	exit (status);
}
