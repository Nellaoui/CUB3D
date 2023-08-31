/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 15:44:44 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	ft_player_direction(t_cub3d *my_struct)
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

t_player	*initilize_player(t_cub3d	*my_struct)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = (ft_give_posx(my_struct->holdmap) * TILE_SIZE) + 25;
	player->y = (ft_give_posy(my_struct->holdmap) * TILE_SIZE) + 25;
	player->direction = 0;
	player->move = 0;
	player->rotate_speed = 10 * (M_PI / 180);
	player->move_speed = 10;
	if (ft_player_direction(my_struct) == 'S')
		player->rotation = M_PI / 2;
	else if (ft_player_direction(my_struct) == 'N')
		player->rotation = -1 * (M_PI / 2);
	else if (ft_player_direction(my_struct) == 'E')
		player->rotation = 360 * (M_PI / 180);
	else if (ft_player_direction(my_struct) == 'E')
		player->rotation = (0 * (M_PI / 180));
	return (player);
}

int	initilize_cub3d(t_cub3d *my_struct)
{
	my_struct->rows = number_of_rows(my_struct->holdmap);
	my_struct->colons = colons(my_struct->holdmap);
	my_struct->width = my_struct->colons * TILE_SIZE;
	my_struct->height = my_struct->rows * TILE_SIZE;
	my_struct->player = initilize_player(my_struct);
	if (my_struct->width > 2560)
		my_struct->width = 2550;
	if (my_struct->height > 1440)
		my_struct->height = 1400;
	my_struct->mlx = mlx_init(my_struct->width, my_struct->height,
			"cub3d", false);
	my_struct->scale_width = (0.1 * my_struct->width) / my_struct->height;
	my_struct->scale_height = (0.2 * my_struct->height) / my_struct->width;
	if (my_struct->mlx == NULL)
		return (1);
	my_struct->image = mlx_new_image(my_struct->mlx,
			my_struct->width, my_struct->height);
	if (my_struct->image == NULL)
		return (1);
	return (0);
}
