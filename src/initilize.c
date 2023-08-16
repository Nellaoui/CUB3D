/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 10:30:45 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_player	*initilize_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->direction = 'S';
	player->rotate_speed = 3 + (M_PI / 180);// should that be modified
	player->move_speed = 3; //increment it to add speed to player
	player->move_direction = 0; // -1 if left +1 is right
	player->turn_direction = M_PI / 2;
	return (player);
}

void	initilize_cub3d(t_cub3d *my_struct)
{
	my_struct->rows = number_of_rows(my_struct->holdmap);
	my_struct->colons = 14;
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


// void	render_map(t_cub3d *mlx_lib)
// {
// 	uint32_t	color;
// 	int			n_colons;

// 	color = 0;
// 	for (int i = 0; i <	mlx_lib->rows; i++)
// 	{
// 		n_colons = number_of_colons(mlx_lib->holdmap[i]);
// 		for (int j = 0; j < n_colons; j++)
// 		{
// 			uint32_t tile_x = j * 50;
// 			uint32_t tile_y = i * 50;
// 			if (mlx_lib->holdmap[i][j] == '0')
// 				color = 0xFFFFFFFF;	
// 			else if (mlx_lib->holdmap[i][j] == '1')
// 				color = 4278190335;
// 			if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx, 50, 50)))
// 				ft_putstr_fd("error in creaitin new_image\n", 2);
// 			mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, tile_x, tile_y);
// 			for (uint16_t i = 0; i < 49; i++)
// 			{
// 				for (uint16_t j = 0; j < 49; j++)
// 					mlx_put_pixel(mlx_lib->image, i, j, color);
// 			}
// 		}
// 	}
// }
