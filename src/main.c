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
	while(!ft_isdigit(str[j][i]))
		i++;
	if (str[j][i + 3] != ',' || str[j][i + 7] != ',')
	{
		ft_putstr_fd("somthing wrong about the color", 2);
		exit(EXIT_FAILURE);
	}
	// printf("(((%s))) i->[%d]" , ft_substr(str[j], i , 3), i);
	st = ft_atoi(ft_substr(str[j], i , 3));
	nd = ft_atoi(ft_substr(str[j], i + 4 , 3));
	rd = ft_atoi(ft_substr(str[j], i + 8, 3));
	// printf("st[%d]  nd[%d]  rd[%d]\n", st, nd, rd);
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
		i = 0;
		while(str[j][i])
		{
			if ((str[j][i] == 'F' || str[j][i] == 'C'))
			{
				ft_check_floor(str, i, j);
				count++;
			}
			i++;
		}
		j++;
	}
	// printf("count --> %d\n", count);
	if (count == 2)
		return 1;
	else
		return (0);
}

int ft_north(char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (1);
		i++;
	}
	return (0);
}
int	ft_west(char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
			return (1);
		i++;
	}
	return (0);
}
int 	ft_east(char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
			return (1);
		i++;
	}
	return (0);
}
int ft_south(char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (1);
		i++;
	}
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
	printf("count --> %d\n", count);
	while(str[j])
	{
		while(str[j][i])
		{
			if (str[j][i] == ' ')
				i++;
			if (str[j][i] == 'N')
			{
				count += ft_north(str[j]);
				break;
			}
			if (str[j][i] == 'W')
			{

				count += ft_west(str[j]);
				break;
			}
			if (str[j][i] == 'E')
			{

				count += ft_east(str[j]);
				break;
			}
			if (str[j][i] == 'S')
			{
				count += ft_south(str[j]);
				break;
			}
			i++;
		}
		j++;
	}
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

