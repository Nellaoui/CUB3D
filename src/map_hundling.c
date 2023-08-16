/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hundling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:26:57 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/15 20:27:42 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


char	**ft_split_map(char *string)
{
	char **splited;
	splited = ft_split(string, '\n');
	if (!splited)
		return (0);
	return (splited);
}

char	*ft_map(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		exit(EXIT_FAILURE);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
}
int	ft_map_line(char **str)
{
	int j;
	int i;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '1' && str[j][i+1] == '1'&&str[j][i+2] == '1'&&str[j][i+3] == '1')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

char **ft_hold_map(char *str)
{
	char **data;
	int j;

	j = give_index(str);
	data = ft_split(&str[j], '\n');
	if(!data)
		return (0);
	return (data);
}

void	ft_double_player(char **map)
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i= 0;
		while(map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' || map[j][i] == 'E' || map[j][i] == 'S')
				count++;
			i++;
		}
		j++;
	}
	if (count > 1)
	{
		ft_putstr_fd("somthing went wrong : to many player in the map", 2);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}
