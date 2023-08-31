/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:50:22 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 17:43:39 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	give_index(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '1' && str[j + 1] == '1'
			&& str[j + 2] == '1' && str[j + 3] != ',')
		{
			while (str[j])
			{
				if (str[j] == '\n' || j == 0)
					return (j);
				j--;
			}
		}
		j++;
	}
	return (0);
}

char	**ft_hold_map(char *str)
{
	int		j;
	char	**data;

	j = give_index(str);
	data = ft_split(&str[j], '\n');
	if (!data)
		return (0);
	return (data);
}

int	st_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\0' && map[i] != ' ' && map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	last_line(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		j++;
	}
	return (j - 1);
}
