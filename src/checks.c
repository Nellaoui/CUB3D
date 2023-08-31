/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 13:50:40 by ndahib           ###   ########.fr       */
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
		exit(1);
	}
}

int	ft_check_floor(char **str, int j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[j][i] == ' ')
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
		if (!ft_isdigit(str[j][i]) && str[j][i] != ',' && str[j][i] != ' ')
			return (1);
		if (str[j][i] == ',')
			count++;
		i++;
	}
	return (ft_check_valid_rgb(str, j, count));
}

int	ft_check_valid_rgb(char **str, int j, int count)
{
	int	st;
	int	nd;
	int	rd;

	st = ft_st(str[j]);
	nd = ft_nd(str[j]);
	rd = ft_rd(str[j]);
	if (st == -1 || nd == -1 || rd == -1)
		return (1);
	if (st >= 0 && st <= 255 && nd >= 0 
		&& nd <= 255 && rd >= 0 && rd <= 255 && count == 2)
		return (0);
	else
		return (1);
}

int	ft_check_dl(char *str)
{
	int	j;

	j = 0;
	if (str == NULL)
		return (1);
	while (str[j])
	{
		if (str[j] == '1' && str[j + 1] == '1' 
			&& str[j + 2] == '1' && str[j + 3] == '1')
			break ;
		j++;
	}
	while (str[j])
	{
		if (str[j] == '\n' && str[j + 1] == '\n')
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_data(char **str)
{
	int	i;
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (str[++j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == 'N')
				count += ft_north(str[j]);
			else if (str[j][i] == 'W')
				count += ft_west(str[j]);
			else if (str[j][i] == 'E')
				count += ft_east(str[j]);
			else if (str[j][i] == 'S')
				count += ft_south(str[j]);
			i++;
		}
	}
	if (count == 4 && ft_rgb(str))
		return (0);
	return (1);
}
