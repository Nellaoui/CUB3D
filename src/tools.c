/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:16:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 10:24:13 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


uint32_t createcolor(int red, int green, int blue, int alpha) 
{
	uint32_t	color;

	color = 0;
	color |= ((uint32_t)alpha) << 24;
	color |= ((uint32_t)blue) << 16;
	color |= ((uint32_t)green) << 8;
	color |= ((uint32_t)red);
	
	return (color);
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


void	printf_double_pointer(char **map)
{
	while (*map != NULL)
	{
		printf("the line is --->%s\n", *map);
		map++;
	}
}