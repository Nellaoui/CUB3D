/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/20 13:52:14 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int	ft_st(char *str)
{
	int i = 0;
	int j = 0;
	int end = 0;
	while (!ft_isdigit(str[j]))
		j++;
	while (str[i])
	{
		if (str[i] == ',')
			break;
		end++;
		i++;
	}
	char *at  = ft_substr(str, j, end - 2);
	if(ft_strncmp("", at, 1) == 0)
	{
		return (-1);
	}
	return (ft_atoi(str));
}

int ft_nd(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	while (str[i])
	{
		if (str[i] == ',' && !end)
			start = i;
		if (str[i] == ',' && start)
			end = i;
		i++;
	}
	char *at;
	at = ft_substr(str, start + 1, end - start - 1);
	if(ft_strncmp("", at, 1) == 0)
		return (-1);
	return (ft_atoi(at));
}

int	ft_rd(char *str)
{
	int i = 0;
	int comma = 0;
	int start = 0;
	while (str[i])
	{
		if (str[i] == ',' && comma != 2)
			comma++;
		if (comma == 2)
		{
			start = i;
			break;
		}
		i++;
	}
	char *at;
	at = ft_substr(str, start + 1, i);
	if(ft_strncmp("", at, 1) == 0)
		return (-1);
	return ft_atoi(at);
}



int	ft_rgb(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(str[j])
	{
		i = 0;
		while(str[j][i])
		{
			if ((str[j][i] == 'F' || str[j][i] == 'C') && str[j][i + 1] == ' ')
			{
				if (ft_check_floor(str, j))
				{
					ft_putstr_fd("somthing went wrong : map can't be loaded", 2);
					exit (1);
				}
			}
			i++;
		}
		j++;
	}
	return (1);
}

int ft_north(char *str)
{
	int	i;

	i = 0;
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
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == 'W' && str[i+1] == 'E' && str[i + 2] == ' ')
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

int	ft_map_line(char **str)
{
	int j;
	int i;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '1' && str[j][i+1] == '1'&&str[j][i+2] == '1'&&str[j][i+3] == '1')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}


int	give_index(char *str)
{
	int j;

	j = 0;
	while(str[j])
	{
		if (str[j] == '1' && str[j+1] == '1' && str[j+2] == '1')
		{
			while(str[j])
			{
				if (str[j] == '\n' || j == 0)
					return (j);
				j--;
			}
		}
		j++;
	}
	return (0);
}

char	**ft_hold_map(char *str)
{
	int		j;
	char	**data;

	j = give_index(str);
	data = ft_split(&str[j], '\n');
	if(!data)
		return (0);
	return (data);
}

int	st_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\0' && map[i] != ' ' && map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	last_line(char **map)
{
	int i;
	int j;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		j++;
	}
	return (j - 1);
}

void	ft_double_player(char **map)
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' || map[j][i] == 'E' || map[j][i] == 'S')
				count++;
			i++;
		}
		j++;
	}
	if (count > 1)
	{
		ft_putstr_fd("somthing went wrong : to many player in the map", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_player(char	**map)
{
	int	i;
	int	j;

	j = 0;
	ft_double_player(map);
	while (map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' || map[j][i] == 'E' || map[j][i] == 'S')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_valid(char **map)
{
	int	i;
	int	j;

	j = 1;
	if (ft_player(map) || st_line(map[0]) || st_line(map[last_line(map)]))
	{
		ft_putstr_fd("somthing went wrong : map issue", 2);
		exit(1);
	}
	while (map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if (ft_good(map, j, i))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_checks(t_cub3d *s, char **av)
{
	char	**file;
	char	*map;

	s->holdmap = NULL;
	map = NULL;
	ft_check_file_cub(av[1]);
	map = ft_map(av[1]);
	if (ft_check_dl(map))
	{
		ft_putstr_fd("somthing went wrong : Double line in the map", 2);
		exit(EXIT_FAILURE);
	}
	file = ft_split_map(map);
	s->holdmap = ft_hold_map(map);
	if (ft_check_valid(s->holdmap) || ft_check_data(file))
		exit(1);
}

void	ft_cub3d(char **av)
{
	t_cub3d	mlx_lib;

	ft_checks(&mlx_lib, av);
	initilize_cub3d(&mlx_lib);
	render_map(&mlx_lib);
	render_player(&mlx_lib);
	mlx_loop(mlx_lib.mlx);
	mlx_terminate(mlx_lib.mlx);
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
	return (0);
}

