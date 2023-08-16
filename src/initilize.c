/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 12:06:42 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


char ft_player_direction(t_cub3d *my_struct)
{
	int i;
	int j;

	j = 0;
	while(my_struct->holdmap[j])
	{
		i = 0;
		while(my_struct->holdmap[j][i])
		{
			if (my_struct->holdmap[j][i] == 'N')
				return 'N';
			if (my_struct->holdmap[j][i] == 'W')
				return 'W';
			if (my_struct->holdmap[j][i] == 'E')
				return 'E';
			if (my_struct->holdmap[j][i] == 'S')
				return 'S';
			i++;
		}
		j++;
	}
	return (NULL);
}

int	ft_give_posy(t_cub3d *my_struct)
{
	int i;
	int j;

	j = 0;
	while(my_struct->holdmap[j])
	{
		i = 0;
		while(my_struct->holdmap[j][i])
		{
			if (my_struct->holdmap[j][i] == 'N' || my_struct->holdmap[j][i] == 'W' || my_struct->holdmap[j][i] == 'E' || my_struct->holdmap[j][i] == 'S')
				return (j);
			i++;
		}
	}
	return (0);
}

int	ft_give_posx(char **str)
{
	int i;
	int j;

	j = 0;
	while(str[j])
	{
		i = 0;
		while(str[j][i])
		{
			if (str[j][i] == 'N' || str[j][i] == 'W' || str[j][i] == 'E' || str[j][i] == 'S')
				return (i);
			i++;
		}
	}
}

t_player	*initilize_player(void)
{
	t_player	*player;
	t_cub3d		*my_struct;

	player = malloc(sizeof(t_player));
	player->x = ft_give_posx(my_struct->holdmap);
	player->y = ft_give_posy(my_struct->holdmap);
	player->direction = ft_player_direction(my_struct);
	player->rotate_speed = 3 + (M_PI / 180);// should that be modified
	player->move_speed = 3; //increment it to add speed to player
	player->move_direction = 0; // -1 if left +1 is right
	player->turn_direction = M_PI / 2;
	return (player);
}

void	initilize_cub3d(t_cub3d *my_struct)
{
	my_struct->rows = number_of_rows(my_struct->holdmap);
	my_struct->colons = 40;
	my_struct->image = NULL;
	my_struct->tile_x = 50;
	my_struct->tile_y = 50;
	my_struct->color = 0xFFFFFFFF;
	my_struct->player = initilize_player(my_struct);
	my_struct->mlx = mlx_init(my_struct->colons * my_struct->tile_x
							, my_struct->rows * my_struct->tile_y
							, "cub3d", true);
	if (my_struct->mlx == NULL)
		ft_putstr_fd("error\n", 2);
}

