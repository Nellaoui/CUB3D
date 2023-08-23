/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/22 18:45:51 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_file_cub(char *string)
{
	int	len;

	len = ft_strlen(string);
	if (string[len - 1] != 'b' || string[len - 2] != 'u'
		|| string[len - 3] != 'c' || string[len - 4] != '.')
	{
		ft_putstr_fd("misiing `.cub` file, Please check it\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_check_floor(char **str, int j)
{
	int	st;
	int	nd;
	int rd;
	int count;
	int i;

	count = 0;
	i = 0;
	while(str[j][i] == ' ')
		i++;
	if (str[j][i] == 'C' || str[j][i] == 'F')
		{
			i++;
			while (str[j][i] == ' ')
				i++;
		}
	else
		return (1);
	while (str[j][i])
	{
		if (!ft_isdigit(str[j][i]) && str[j][i] != ',')
			return (1);
		if (str[j][i] == ',')
			count++;
				i++;
	}
	st = ft_st(str[j]);
	nd = ft_nd(str[j]);
	rd = ft_rd(str[j]);
	if (st == -1 || nd == -1 || rd == -1)
		return (1);
	if (st >= 0 && st <= 255 && nd >= 0 && nd <= 255 && rd >= 0 && rd <= 255 && count == 2)
		return (0);
	else
		return (1);
}

int	ft_check_dl(char *str)
{
	int j;

	j = 0;
	while(str[j])
	{
		if (str[j] == '1' && str[j+1] == '1' && str[j+2] == '1' && str[j+3] == '1')
			break ;
		j++;
	}
	while(str[j])
	{
		if (str[j] == '\n' && str[j+1] == '\n')
			return 1;
		j++;
	}
	return (0);
}

int	ft_check_data(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while(str[j])
	{
		i = 0;
		while(str[j][i])
		{
			if (str[j][i] == ' ')
				i++;
			if (str[j][i] == 'N')
				count += ft_north(str[j]);
			if (str[j][i] == 'W')
				count += ft_west(str[j]);
			if (str[j][i] == 'E')
				count += ft_east(str[j]);
			if (str[j][i] == 'S')
				count += ft_south(str[j]);
			i++;
		}
		j++;
	}
	if (count == 4 && ft_rgb(str))
		return 0;
	ft_putstr_fd("somthing went wrong : map can't be loaded", 2);
		exit(EXIT_FAILURE);
}

int	ft_good(char **map, int j, int i)
{
	if (map[j][i] == '0' || map[j][i]  == 'W' || map[j][i]  == 'E' || map[j][i]  == 'N' || map[j][i]  == 'S')
	{
		if (ft_strlen(map[j - 1]) < (unsigned long)i)
			return (1);
		if (ft_strlen(map[j + 1]) < (unsigned long)i)
			return (1);
		if (map[j - 1][i] == ' ' || map[j - 1][i] == '\0')
			return (1);
		if (map[j + 1][i] == ' ' || map[j + 1][i] == '\0')
			return (1);
		if (map[j][i + 1] == ' ' || map[j][i + 1] == '\0')
			return (1);
		if (map[j][i - 1] == ' ' || map[j][i - 1] == '\0')
			return (1);
	}
	return (0);
}

// void	ft_check_map(char **str)
// {
// 	int i;
// 	int j = 0;
// 	while(str[j])
// 	{
// 		i = 0;
// 		while (str[i])
// 		{
// 			str[]
// 			i++;
// 		}
// 		j++;
// 	}
// }

// int	ft_check_dl(char **str)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (str[j])
// 	{
// 		i = 0;
// 		while (str[j][i])
// 		{
// 			if (str[j][i] == '1' )
// 			i++;
// 		}
// 	}
// 	return (false);
// }

