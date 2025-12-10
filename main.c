#include "cub3d.h"

int	main(int ac, char **av)
{
	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	printf("ok");
	return (EXIT_SUCCESS);
}
