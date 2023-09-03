/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hundling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:26:57 by nelallao          #+#    #+#             */
/*   Updated: 2023/09/03 17:58:15 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_map(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		exit(EXIT_FAILURE);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n somthing went wrong with the fd\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
}

int	ft_map_line(char **str)
{
	int	j;
	int	i;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '1' && str[j][i + 1] == '1'
				&& str[j][i + 2] == '1' && str[j][i + 3] == '1')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_double_p(char **map)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W'
				|| map[j][i] == 'E' || map[j][i] == 'S')
				count++;
			i++;
		}
		j++;
	}
	if (count > 1)
	{
		ft_putstr_fd("Error\n To many p\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_wall_here_a(float x, float y, t_cub3d	*mlx)
{
	int	x_grid;
	int	y_grid;

	x_grid = (int)(x / TILE_SIZE);
	y_grid = (int)(y / TILE_SIZE);
	if (x < 0 || x > TILE_SIZE * mlx->colons 
		|| y < 0 || y > TILE_SIZE * mlx->rows)
		return (1);
	if (x < 0 || x + 1 > TILE_SIZE * mlx->colons 
		|| y < 0 || y + 1 > TILE_SIZE * mlx->rows)
		return (1);
	if (mlx->holdmap[y_grid][x_grid] != '1')
		return (0);
	return (1);
}
