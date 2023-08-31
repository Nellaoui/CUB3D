/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:06:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/30 10:24:58 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_double_player(char **map)
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
		ft_putstr_fd("somthing went wrong : to many player in the map", 2);
		return ;
	}
}

char	**ft_split_map(char *string)
{
	char	**splited;

	splited = ft_split(string, '\n');
	if (!splited)
		return (0);
	return (splited);
}
