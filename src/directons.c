/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 15:24:35 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


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
