/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 16:31:13 by ndahib           ###   ########.fr       */
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
	return (ft_check_valid_rgb(str, j, count, s));
}

void	ft_give_color(char	**str, t_cub3d *s, int f_c, int j)
{
	static int	two;

	if (f_c == 1)
	{
		s->f_st = ft_st(str[j]);
		s->f_nd = ft_nd(str[j]);
		s->f_rd = ft_rd(str[j]);
		two++;
	}
	if (f_c == 2)
	{
		s->c_st = ft_st(str[j]);
		s->c_nd = ft_nd(str[j]);
		s->c_rd = ft_rd(str[j]);
		two++;
	}
	if (two > 2)
	{
		exit(EXIT_FAILURE);
		ft_putstr_fd("Error\n", 2);
	}
}

int	ft_check_valid_rgb(char **str, int j, int count, t_cub3d *s)
{
	int			st;
	int			nd;
	int			rd;
	int			f;
	int			i;
	static int	two;

	f = false;
	i = 0;
	if (str[j][i] == 'F')
		f = 1;
	if (str[j][i] == 'C')
		f = 2;
	st = ft_st(str[j]);
	nd = ft_nd(str[j]);
	rd = ft_rd(str[j]);
	if (st == -1 || nd == -1 || rd == -1)
		return (1);
	if (st >= 0 && st <= 255 
		&& nd >= 0 && nd <= 255 && rd >= 0 && rd <= 255 && count == 2)
	{
		ft_give_color(str, s, f, j);
		return (0);
	}
	else
		return (1);
}

int	ft_check_dl(char *str)
{
	int	j;

	j = 0;
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
