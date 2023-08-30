/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:17:17 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/30 18:45:14 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	ft_directions(char **str, int j, int i)
// {
// 	static int count = 0;

// 	if (str[j][i] == 'N')
// 		count += ft_north(str[j]);
// 	if (str[j][i] == 'W')
// 		count += ft_west(str[j]);
// 	if (str[j][i] == 'E')
// 		count += ft_east(str[j]);
// 	if (str[j][i] == 'S')
// 		count += ft_south(str[j]);
// 	return (count);
// }


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
