/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 11:11:24 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_player	*initilize_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->direction = 'E';
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
	my_struct->player = initilize_player();
	my_struct->mlx = mlx_init(my_struct->colons * my_struct->tile_x
							, my_struct->rows * my_struct->tile_y
							, "cub3d", true);
	if (my_struct->mlx == NULL)
		ft_putstr_fd("error\n", 2);
}

