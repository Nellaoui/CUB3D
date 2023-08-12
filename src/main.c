#include "../includes/cub3d.h"

char	**ft_split_map(char *string)
{
	char **splited;
	splited = ft_split(string, '\n');
	if (!splited)
		return (0);
	return (splited);
}

char	*ft_map(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		exit(EXIT_FAILURE);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
}

void	ft_checks(t_cub3d *s, char **av)
{
	ft_check_file_cub(av[1]);
	s->map = ft_map(av[1]);
	ft_split_map(s->map);
}

void	ft_cub3d(char **av)
{
	t_cub3d s;

	ft_checks(&s, av);
}
int main(int ac, char **av)
{
	ac = 0;
	if (ac == 2)
		ft_cub3d(av);
	else
	{
		ft_putstr_fd("Error : Number of arguments isn't Correct\n", 2);
		return (1);
	}
	// mlx_t* mlx = mlx_init(500, 500, "znn", true);

	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (0);
}
