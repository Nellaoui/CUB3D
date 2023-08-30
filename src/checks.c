/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/30 21:59:29 by nelallao         ###   ########.fr       */
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

int	ft_check_floor(char **str, int j, t_cub3d *s)
{
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
		if (!ft_isdigit(str[j][i]) && str[j][i] != ',' && str[j][i] != ' ')
			return (1);
		if (str[j][i] == ',')
			count++;
		i++;
	}
	if (ft_check_valid_rgb(str, j, count, s))
		return (1);
	return (0);
}

void	ft_give_color(char	**str, t_cub3d *s, int f_c, int j)
{
	if (f_c == 1)
	{
		s->f_st = ft_st(str[j]);
		s->f_nd = ft_nd(str[j]);
		s->f_rd = ft_rd(str[j]);
	}
	if (f_c == 2)
	{
		s->c_st = ft_st(str[j]);
		s->c_nd = ft_nd(str[j]);
		s->c_rd = ft_rd(str[j]);
	}
}

int ft_check_valid_rgb(char **str, int j, int count, t_cub3d *s)
{
	int	st;
	int	nd;
	int rd;
	int	f = false;
	int	i = 0;

	// while(str[j][i] != ' ')
	// 	i++;
	if (str[j][i] == 'F')
		f = 1;
	if (str[j][i] == 'C')
		f = 2;
	st = ft_st(str[j]);
	nd = ft_nd(str[j]);
	rd = ft_rd(str[j]);

	if (st == -1 || nd == -1 || rd == -1)
		return (1);
	if (st >= 0 && st <= 255 && nd >= 0 && nd <= 255 && rd >= 0 && rd <= 255 && count == 2)
	{
		ft_give_color(str, s, f, j);
		return (0);
	}
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

// void	ft_check_st_wall(char **str)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (str[j])
// 	{
// 		while(str[j][] != '1')
// 	}
// }

int	ft_chek_invalid(char **str)
{
	int i;
	int j;
	j =0;
	while (str[j])
	{
		i = 0;
		while(str[j][i])
		{
			if(str[j][i] != '1' && str[j][i] != '0' && str[j][i] != 'W' && str[j][i] != 'S' && str[j][i] != 'N' && str[j][i] != 'E')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
int	ft_check_data(char **str, t_cub3d *s)
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
			if (str[j][i] == 'N')
				count += ft_north(str[j], s);
			else if (str[j][i] == 'W')
				count += ft_west(str[j], s);
			else if (str[j][i] == 'E')
				count += ft_east(str[j], s);
			else if (str[j][i] == 'S')
				count += ft_south(str[j], s);
			i++;
		}
		j++;
	}
	if (count == 4 && ft_rgb(str, s))
		return 0;
	ft_putstr_fd("somthing went wrong : map can't be loaded 1", 2);
		exit(EXIT_FAILURE);
}

int	ft_good(char **map, int j, int i)
{
	if (map[j][0] == '0')
		return 1;
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
