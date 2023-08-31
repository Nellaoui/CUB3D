/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:17:17 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 13:53:20 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_directions(char **str, int j, int i)
{
	static int	count;

	if (str[j][i] == 'N')
		count += ft_north(str[j]);
	if (str[j][i] == 'W')
		count += ft_west(str[j]);
	if (str[j][i] == 'E')
		count += ft_east(str[j]);
	if (str[j][i] == 'S')
		count += ft_south(str[j]);
	return (count);
}

int	ft_check_valid(char **map)
{
	int	i;
	int	j;

	j = 1;
	if (ft_player(map) || st_line(map[0]) || st_line(map[last_line(map)]))
	{
		ft_putstr_fd("somthing went wrong : map issue", 2);
		return (1);
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

int	ft_good(char **map, int j, int i)
{
	if (map[j][0] == '0')
		return (1);
	if (map[j][i] == '0' || map[j][i] == 'W'
		|| map[j][i] == 'E' || map[j][i] == 'N' || map[j][i] == 'S')
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

int	ft_rgb(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if ((str[j][i] == 'F' || str[j][i] == 'C') && str[j][i + 1] == ' ')
			{
				if (ft_check_floor(str, j))
				{
					ft_putstr_fd("somthing went wrong:map can't be loaded", 2);
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (1);
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
			if (str[j][i] != '1' 
				&& str[j][i] != '0' 
				&& str[j][i] != 'W' 
				&& str[j][i] != 'S' 
				&& str[j][i] != 'N' 
				&& str[j][i] != 'E' 
				&& str[j][i] != ' ')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
