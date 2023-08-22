/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:28:25 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/22 19:38:36 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	ft_st(char *str)
{
	int i = 0;
	int j = 0;
	int end = 0;
	while (!ft_isdigit(str[j]))
		j++;
	while (str[i])
	{
		if (str[i] == ',')
			break;
		end++;
		i++;
	}
	char *at  = ft_substr(str, j, end - 2);
	if(ft_strncmp("", at, 1) == 0)
	{
		return (-1);
	}
	return (ft_atoi(str));
}


int ft_nd(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;
	while (str[i])
	{
		if (str[i] == ',' && !end)
			start = i;
		if (str[i] == ',' && start)
			end = i;
		i++;
	}
	char *at;
	at = ft_substr(str, start + 1, end - start - 1);
	if(ft_strncmp("", at, 1) == 0)
		return (-1);
	return (ft_atoi(at));
}

int	ft_rd(char *str)
{
	int i = 0;
	int comma = 0;
	int start = 0;
	while (str[i])
	{
		if (str[i] == ',' && comma != 2)
			comma++;
		if (comma == 2)
		{
			start = i;
			break;
		}
		i++;
	}
	char *at;
	at = ft_substr(str, start + 1, i);
	if(ft_strncmp("", at, 1) == 0)
		return (-1);
	return ft_atoi(at);
}
int st_line(char *map)
{
	int i;
	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\0' && map[i] != ' '&& map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
