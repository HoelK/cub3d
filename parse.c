#include "cub3d.h"

bool	check_path(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(&path[len - 4], ".cub", 4))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	check_args(int ac, char **av)
{
	if (ac != 2 || !check_path(av[1]))
		return (false);
	return (true);
}
