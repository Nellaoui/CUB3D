/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 16:44:42 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_give_path(char *str, t_cub3d *s)
{
	int			i;
	char		*path;
	static int	texture_number;

	i = 0;
	while (str[i] != '.')
		i++;
	path = ft_substr(str, i, ft_strlen(str) - i);
	s->texture[texture_number] = mlx_load_png(path);
	if (!(s->texture[texture_number]))
	{
		ft_putstr_fd("Error\n texture cant be loaded", 2);
		exit(1);
	}
	texture_number++;
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
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
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
		ft_putstr_fd("Error\n double line", 2);
		exit(EXIT_FAILURE);
	}
	file = ft_split_map(map);
	s->holdmap = ft_hold_map(map);
	if (ft_check_valid(s->holdmap) || ft_check_data(file, s) 
		|| ft_chek_invalid(s->holdmap))
	{
		ft_putstr_fd("Error\n invalid data", 2);
		exit(1);
	}
}

void	ft_cub3d(char **av)
{
	t_cub3d	mlx_lib;

	ft_checks(&mlx_lib, av);
	if (initilize_cub3d(&mlx_lib))
	{
		free(mlx_lib.player);
		mlx_terminate(mlx_lib.mlx);
		exit(1);
	}
	render_map(&mlx_lib);
	render_player(&mlx_lib);
	mlx_loop(mlx_lib.mlx);
	mlx_terminate(mlx_lib.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_cub3d(av);
	else
	{
		ft_putstr_fd("Error\n number of Argumment not correct\n", 2);
		return (1);
	}
	return (0);
}
