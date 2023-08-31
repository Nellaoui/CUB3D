/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 22:15:44 by nelallao         ###   ########.fr       */
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
		mlx_delete_texture(s->texture[texture_number]);
		free(path);
		exit(1);
	}
	free(path);
	texture_number++;
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
		ft_putstr_fd("Error\nDouble line", 2);
		exit(EXIT_FAILURE);
	}
	file = ft_split_map(map);
	s->holdmap = ft_hold_map(map);
	if (ft_check_valid(s->holdmap) || ft_check_data(file, s)
		|| ft_chek_invalid(s->holdmap))
	{
		ft_putstr_fd("Error\nInvalid data", 2);
		free_double_pointer(file);
		exit(1);
	}
	free_double_pointer(file);
}

void	ft_cub3d(char **av)
{
	t_cub3d	mlx_lib;

	ft_checks(&mlx_lib, av);
	if (initilize_cub3d(&mlx_lib))
	{
		free(mlx_lib.p);
		mlx_terminate(mlx_lib.mlx);
		exit(1);
	}
	render_p(&mlx_lib);
	mlx_loop(mlx_lib.mlx);
	free(mlx_lib.p);
	free(mlx_lib.holdmap);
	mlx_terminate(mlx_lib.mlx);
}

int	ft_wall_here(float x, float y, t_cub3d *mlx)
{
	if (x < 0
		|| x > TILE_SIZE * mlx->colons
		|| y < 0
		|| y > TILE_SIZE * mlx->rows)
		return (1);
	if (mlx->holdmap[(int)((y + 2) / TILE_SIZE)][(int)((x) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y - 2) / TILE_SIZE)][(int)((x) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y) / TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y) / TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] != '1')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_cub3d(av);
	else
	{
		ft_putstr_fd("Error\nnumber of Argumment not correct\n", 2);
		return (1);
	}
	return (0);
}
