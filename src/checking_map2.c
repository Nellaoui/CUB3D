/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:03:04 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 10:28:53 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	give_index(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '1' && str[j + 1] == '1' 
			&& str[j + 2] == '1' && str[j + 3] == '1')
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

char	*ft_map(char *string)
{
	int			fd;
	static char	map_data[500000];

	fd = open(string, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		return (NULL);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		return (NULL);
	return (map_data);
}
