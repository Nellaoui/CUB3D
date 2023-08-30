/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/30 17:19:06 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// int ft_north(char *str, t_cub3d *s)
// {
// 	int i = 0;

// 	while (str[i] == ' ')
// 		i++;
// 	while(str[i])
// 	{
// 		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
// 		{
// 			ft_give_path(str, s);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_west(char *str, t_cub3d *s)
// {
// 	int i = 0;

// 	while (str[i] == ' ')
// 		i++;
// 	while(str[i])
// 	{
// 		if (str[i] == 'W' && str[i+1] == 'E' && str[i + 2] == ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int 	ft_east(char *str)
// {
// 	int i = 0;

// 	while (str[i] == ' ')
// 		i++;
// 	while(str[i])
// 	{
// 		if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int ft_south(char *str)
// {
// 	int i = 0;

// 	while (str[i] == ' ')
// 		i++;
// 	while(str[i])
// 	{
// 		if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	ft_player(char	**map)
{
	int i;
	int j;

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
