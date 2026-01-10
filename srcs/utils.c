#include "cub3d.h"

int	rgb_to_hex(uint8_t *rgb)
{
	return (((rgb[R] & 0xff) << 16) + ((rgb[G] & 0xff) << 8) + (rgb[B] & 0xff));
}

float	angle_to_radian(int angle)
{
	return (angle * (PI / 180.0));
}
