/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 16:46:52 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_split_map(char *string)
{
	char	**splited;

	splited = ft_split(string, '\n');
	if (!splited)
		return (0);
	return (splited);
}

int	ft_player(char	**map)
{
	int	i;
	int	j;

	j = 0;
	ft_double_player(map);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' 
				|| map[j][i] == 'E' || map[j][i] == 'S')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_st(char *str)
{
	int		i;
	int		j;
	int		end;
	char	*at;
	int		nbr;

	i = 0;
	j = 0;
	end = 0;
	while (!ft_isdigit(str[j]))
		j++;
	while (str[i])
	{
		if (str[i] == ',')
			break ;
		end++;
		i++;
	}
	at = ft_substr(str, j, end - 2);
	if (ft_strncmp("", at, 1) == 0)
		return (-1);
	nbr = ft_atoi(at);
	free(at);
	return (nbr);
}

int	ft_nd(char *str)
{
	int		i;
	int		j;
	int		end;
	char	*at;
	int		nbr;

	i = 0;
	j = 0;
	end = 0;
	while (str[i])
	{
		if (str[i] == ',' && !end)
			j = i;
		if (str[i] == ',' && j)
			end = i;
		i++;
	}
	at = ft_substr(str, j + 1, end - j - 1);
	if (ft_strncmp("", at, 1) == 0)
		return (-1);
	nbr = ft_atoi(at);
	free(at);
	return (nbr);
}

int	ft_rd(char *str)
{
	int		i;
	int		comma;
	int		start;
	char	*at;
	int		nbr;

	i = -1;
	comma = 0;
	start = 0;
	while (str[++i])
	{
		if (str[i] == ',' && comma != 2)
			comma++;
		if (comma == 2)
		{
			start = i;
			break ;
		}
	}
	at = ft_substr(str, start + 1, i);
	if (ft_strncmp("", at, 1) == 0)
		return (-1);
	nbr = ft_atoi(at);
	free(at);
	return (nbr);
}
