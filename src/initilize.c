/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/09/03 17:56:45 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	ft_p_direction(t_cub3d *my_struct)
{
	int	i;
	int	j;

	j = 0;
	while (my_struct->holdmap[j])
	{
		i = 0;
		while (my_struct->holdmap[j][i])
		{
			if (my_struct->holdmap[j][i] == 'N')
				return ('N');
			if (my_struct->holdmap[j][i] == 'W')
				return ('W');
			if (my_struct->holdmap[j][i] == 'E')
				return ('E');
			if (my_struct->holdmap[j][i] == 'S')
				return ('S');
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_give_posy(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W'
				|| map[j][i] == 'E' || map[j][i] == 'S')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_give_posx(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == 'N' || str[j][i] == 'W'
				|| str[j][i] == 'E' || str[j][i] == 'S')
				return (i);
			i++;
		}
		j++;
	}
	return (0);
}

t_p	*initilize_p(t_cub3d	*my_struct)
{
	t_p	*p;

	p = malloc(sizeof(t_p));
	if (!p)
		return (NULL);
	p->x = (ft_give_posx(my_struct->holdmap) * TILE_SIZE) + 25;
	p->y = (ft_give_posy(my_struct->holdmap) * TILE_SIZE) + 25;
	p->direction = 0;
	p->move = 0;
	p->rotate_speed = 10 * (M_PI / 180);
	p->move_speed = 10;
	if (ft_p_direction(my_struct) == 'S')
		p->rotation = M_PI / 2;
	else if (ft_p_direction(my_struct) == 'N')
		p->rotation = -1 * (M_PI / 2);
	else if (ft_p_direction(my_struct) == 'E')
		p->rotation = 360 * (M_PI / 180);
	else if (ft_p_direction(my_struct) == 'W')
		p->rotation = (0 * (M_PI / 180));
	return (p);
}

int	initilize_cub3d(t_cub3d *my_struct)
{
	my_struct->rows = number_of_rows(my_struct->holdmap);
	my_struct->colons = colons(my_struct->holdmap);
	my_struct->width = WIDGHT;
	my_struct->height = HEIGHT;
	my_struct->p = initilize_p(my_struct);
	if ((my_struct->colons * TILE_SIZE) > 9600 
		|| ((my_struct->rows * TILE_SIZE) > 5400))
		my_struct->map_size = 1;
	my_struct->mlx = mlx_init(my_struct->width, my_struct->height,
			"cub3d", false);
	my_struct->scale_width = 0.1;
	my_struct->scale_height = 0.1;
	if (my_struct->mlx == NULL)
		return (1);
	my_struct->image = mlx_new_image(my_struct->mlx,
			WIDGHT, HEIGHT);
	if (my_struct->image == NULL)
		return (1);
	return (0);
}
