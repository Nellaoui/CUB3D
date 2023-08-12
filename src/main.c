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

int	ft_check_floor(char **str, int i, int j)
{
	int	st;
	int	nd;
	int rd;
	st = ft_atoi(ft_substr(str[j], i , 3));
	nd = ft_atoi(ft_substr(str[j], i + 4 , 3));
	rd = ft_atoi(ft_substr(str[j], i + 8, 3));
	if (st >= 0 && st <= 255 && nd >= 0 && nd <= 255 && rd >= 0 && rd <= 255)
		return (1);
	return (0);
}

int	ft_rgb(char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;

	while(str[j])
	{
		while(str[j][i])
		{
			if ((ft_check_floor(str, i, j)) && (str[j][i] == 'F' || str[j][i] == 'C'))
				count++;
			i++;
		}
		j++;
	}
	if (count == 2)
		return 1;
	else
		return (0);
}

int	ft_check_data(char **str)
{
	int i;
	int j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while(str[j])
	{
		while(str[j][i])
		{
			if (str[j][i] == 'N' && str[j][i + 1] == 'O' && str[j][i + 2] == ' ')
				count++;
			else if (str[j][i] == 'W' && str[j][i + 1] == 'E' && str[j][i + 2] == ' ')
				count++;
			else if (str[j][i] == 'E' && str[j][i + 1] == 'A' && str[j][i + 2] == ' ')
				count++;
			if (str[j][i] == 'S' && str[j][i + 1] == 'O' && str[j][i + 2] == ' ')
				count++;
			i++;
		}
		j++;
	}
	printf("count --> %d\n", count);
	if (count == 4 && ft_rgb(str))
		return 1;
	return (0);
}

void	ft_checks(t_cub3d *s, char **av)
{
	char **map_double;
	ft_check_file_cub(av[1]);
	s->map = ft_map(av[1]);
	map_double = ft_split_map(s->map);
	if (ft_check_data(map_double))
		puts("GOOOOOOOD");
	else
		puts("NOOOOOOT   GOOOOOOOD");
	printf("%s\n", map_double[1]);
	printf("%s\n", map_double[2]);
	printf("%s\n", map_double[3]);
	printf("%s\n", map_double[4]);
	printf("%s\n", map_double[5]);
	printf("%s\n", map_double[6]);
	printf("%s\n", map_double[7]);
}

void	ft_cub3d(char **av)
{
	t_cub3d s;

	ft_checks(&s, av);
}
int main(int ac, char **av)
{
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

