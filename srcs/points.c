#include "cub3d.h"

void	print_point(t_point vec, const char *name)
{
	printf("%s : [x : %f][y : %f]\n", name, vec.x, vec.y);
}

t_point	get_point(float x, float y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point rotate_point_around(t_point center, t_point point, double angle)
{
    t_point result;
    
    double rel_x = point.x - center.x;
    double rel_y = point.y - center.y;
    
    double rotated_x = rel_x * cos(angle) - rel_y * sin(angle);
    double rotated_y = rel_x * sin(angle) + rel_y * cos(angle);
    
    result.x = rotated_x + center.x;
    result.y = rotated_y + center.y;
    result.x = rotated_x + center.x;
    result.y = rotated_y + center.y;
    
    return result;
}
