/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:17:17 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/16 10:42:07 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_directions(char **str, int j, int i)
{
	static int count = 0;

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
		i = 0;
		while(str[j][i])
		{
			if (str[j][i] == ' ')
				i++;
			count = ft_directions(str, j, i);
			i++;
		}
		j++;
	}
	if (count == 4 && ft_rgb(str))
		return 0;
	printf("[%d]  [%d]  \n", count, ft_rgb(str));
	ft_putstr_fd("somthing went wrong : map can't be loaded", 2);
		exit(EXIT_FAILURE);
}


int	ft_check_valid(char **map)
{
	int i;
	int j;

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
