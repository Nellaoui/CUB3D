/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:47:04 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 20:53:33 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	ft_rgb(char **str, t_cub3d *s)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if ((str[j][i] == 'F' || str[j][i] == 'C') && str[j][i + 1] == ' ')
			{
				if (ft_check_floor(str, j, s))
				{
					ft_putstr_fd("Error\n", 2);
					exit (1);
				}
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_north(char *str, t_cub3d *s)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		{
			ft_give_path(str, s);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_west(char *str, t_cub3d *s)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		{
			ft_give_path(str, s);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_east(char *str, t_cub3d *s)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		{
			ft_give_path(str, s);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_south(char *str, t_cub3d *s)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		{
			ft_give_path(str, s);
			return (1);
		}
		i++;
	}
	return (0);
}
