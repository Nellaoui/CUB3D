/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:28:25 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 13:53:47 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_st(char *str)
{
	int		i;
	int		j;
	int		end;
	char	*at;

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
	{
		return (-1);
	}
	free(at);
	return (ft_atoi(str));
}

int	ft_nd(char *str)
{
	int		i;
	int		start;
	int		end;
	char	*at;

	i = 0;
	start = 0;
	end = 0;
	while (str[i])
	{
		if (str[i] == ',' && !end)
			start = i;
		if (str[i] == ',' && start)
			end = i;
		i++;
	}
	at = ft_substr(str, start + 1, end - start - 1);
	if (ft_strncmp("", at, 1) == 0)
		return (-1);
	free(at);
	return (ft_atoi(at));
}

int	ft_rd(char *str)
{
	int		i;
	int		comma;
	int		start;
	char	*at;

	i = 0;
	comma = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ',' && comma != 2)
			comma++;
		if (comma == 2)
		{
			start = i;
			break ;
		}
		i++;
	}
	at = ft_substr(str, start + 1, i);
	if (ft_strncmp("", at, 1) == 0)
		return (-1);
	free(at);
	return (ft_atoi(at));
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

void	ft_checks(t_cub3d *s, char **av)
{
	char	**file;
	char	*map;

	s->holdmap = NULL;
	map = NULL;
	ft_check_file_cub(av[1]);
	map = ft_map(av[1]);
	if (ft_check_dl(map))
	{
		ft_putstr_fd("somthing went wrong : Double line in the map", 2);
		exit(EXIT_FAILURE);
	}
	file = ft_split_map(map);
	s->holdmap = ft_hold_map(map);
	if (ft_check_valid(s->holdmap) || ft_check_data(file) 
		|| ft_chek_invalid(s->holdmap))
	{
		free_double_pointer(file);
		ft_putstr_fd("somthing went wrong : data is not valid", 2);
		exit(1);
	}
	free_double_pointer(file);
}
