/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:16:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 13:58:26 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	createcolor(int red, int green, int blue, float alpha)
{
	int	hex;

	hex = (red << 24) | (green << 16) | (blue << 8) | (int)(alpha);
	return (hex);
}

// void	printf_double_pointer(char **map)
// {
// 	while (*map != NULL)
// 	{
// 		printf("the line is --->%s\n", *map);
// 		map++;
// 	}
// }

int	colons(char **map)
{
	int				j;
	unsigned long	holder;

	j = 1;
	holder = 0;
	while (map[j])
	{
		if (ft_strlen(map[j]) >= holder)
			holder = ft_strlen(map[j]);
		j++;
	}
	return (holder);
}

int	number_of_rows(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

void	free_double_pointer(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

double	ft_absolute_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, (2 * M_PI));
	if (ray_angle < 0)
		ray_angle += (2 * M_PI);
	return (ray_angle);
}
