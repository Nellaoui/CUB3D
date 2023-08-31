/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:16:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 15:46:45 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


uint32_t createcolor(int red, int green, int blue, float alpha)
{
	int	hex;

	hex = (red << 24) | (green << 16) | (blue << 8) | (int)(alpha);
	return (hex);
    // int color = 0;
    // color |= (int)(blue * 255);
    // color |= (int)(green * 255) << 8;
    // color |= (int)(red * 255) << 16;
    // color |= (int)(alpha * 255) << 24;
    // return (color);
// }

	// return (alpha << 24 | red << 16 | green << 8 | blue);
	// uint32_t	color;

	// color = 0;
	// color |= ((uint32_t)alpha) << 24;
	// color |= ((uint32_t)blue) << 16;
	// color |= ((uint32_t)green) << 8;
	// color |= ((uint32_t)red);

	// return (color);
}

int number_of_rows(char **map)
{
	int count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	number_of_colons(char *map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}


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

void	printf_double_pointer(char **map)
{
	while (*map != NULL)
	{
		printf("the line is --->%s\n", *map);
		map++;
	}
}

double	ft_absolute_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, (2 * M_PI));
	if (ray_angle < 0)
		ray_angle += (2 * M_PI);
	return (ray_angle);
}

