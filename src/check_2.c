/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:17:17 by nelallao          #+#    #+#             */
/*   Updated: 2023/09/03 21:07:29 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_valid(char **map)
{
	int	i;
	int	j;

	j = 1;
	if (ft_p(map) || st_line(map[0]) || st_line(map[last_line(map)]))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (ft_good(map, j, i))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_chek_invalid(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != '1' && str[j][i] != '0'
				&& str[j][i] != 'W' && str[j][i] != 'S'
				&& str[j][i] != 'N' && str[j][i] != 'E'
				&& str[j][i] != ' ')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_data(char **str, t_cub3d *s)
{
	int	i;
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] == 'N')
				count += ft_north(str[j], s);
			else if (str[j][i] == 'W')
				count += ft_west(str[j], s);
			else if (str[j][i] == 'E')
				count += ft_east(str[j], s);
			else if (str[j][i] == 'S')
				count += ft_south(str[j], s);
		}
	}
	ft_hardcode(str);
	if (count == 4 && ft_rgb(str, s))
		return (0);
	return (1);
}

int	ft_good(char **map, int j, int i)
{
	if (map[j][0] == '0')
		return (1);
	if (map[j][i] == '0'
		|| map[j][i] == 'W' || map[j][i] == 'E'
		|| map[j][i] == 'N' || map[j][i] == 'S')
	{
		if (ft_strlen(map[j - 1]) < (unsigned long)i)
			return (1);
		if (ft_strlen(map[j + 1]) < (unsigned long)i)
			return (1);
		if (map[j - 1][i] == ' ' || map[j - 1][i] == '\0')
			return (1);
		if (map[j + 1][i] == ' ' || map[j + 1][i] == '\0')
			return (1);
		if (map[j][i + 1] == ' ' || map[j][i + 1] == '\0')
			return (1);
		if (map[j][i - 1] == ' ' || map[j][i - 1] == '\0')
			return (1);
	}
	return (0);
}

void	ft_norm(t_cub3d *mlx)
{
	render_p(mlx);
	cast_ray(mlx);
	if (mlx->map_press == 1)
	{
		render_map(mlx);
		draw_p(mlx);
	}
}
