/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:41:12 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/24 19:47:32 by nelallao         ###   ########.fr       */
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
	return (0);
}

int	ft_give_posy(char **map)
{
	int	i;
	int	j;

	j = 0;
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'W' || map[j][i] == 'E' || map[j][i] == 'S')
				return (j);
			i++;
		}
		j++;
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
		j++;
	}
	return (0);
}

t_player	*initilize_player(t_cub3d	*my_struct)
{
	t_player	*player;
	(void)my_struct;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = ft_give_posx(my_struct->holdmap) * 50;
	player->y = ft_give_posy(my_struct->holdmap) * 50;
	player->direction = 0; // left or right //ft_player_direction(my_struct);
	player->move = 0; // back or front
	player->rotate_speed = 10 * (M_PI / 180);
	player->move_speed = 10;
	player->rotation = M_PI / 2;
	return (player);
}
/*by noaman ilook for the biig len and i return thier lane*/
int	colons(char **map)
{
	int j;
	unsigned long holder;

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

void	initilize_cub3d(t_cub3d *my_struct)
{
	my_struct->rows = number_of_rows(my_struct->holdmap);
	my_struct->colons = colons(my_struct->holdmap);
	my_struct->image = NULL;
	my_struct->tile_x = TILE_SIZE;
	my_struct->tile_y = TILE_SIZE;
	my_struct->color = 0xFFFFFFFF;
	my_struct->width = my_struct->colons * my_struct->tile_x;
	my_struct->height = my_struct->rows * my_struct->tile_y;
	my_struct->player = initilize_player(my_struct);

	my_struct->mlx = mlx_init(my_struct->colons * my_struct->tile_x
							, my_struct->rows * my_struct->tile_y
							, "cub3d", true);
	if (my_struct->mlx == NULL)
		ft_putstr_fd("error\n", 2);
}
// }
// void	draw_player(void *param)
// {
// 	t_cub3d	*mlx;
// 	uint32_t	x;

// 	mlx = param;
// 	if (mlx->player->direction == 'S')
// 	{
// 		for (uint32_t i = 0; i < mlx->image->width/2; i++)
// 		{
// 			for (uint32_t j = 0; j < mlx->image->height/2; j++)
// 			mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
// 		}
// 		x = mlx->image->width/4;
// 		for (uint32_t y = mlx->image->height/2 ; y < mlx->image->height; y++)
// 			mlx_put_pixel(mlx->image, x, y, 0x0FFFFFFF);
// 	}
// 	else if (mlx->player->direction == 'E')
// 	{
// 		for (uint32_t i = 0; i < mlx->image->width/2; i++)
// 		{
// 			for (uint32_t j = 0; j < mlx->image->height/2; j++)
// 			mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
// 		}
// 		x = mlx->image->width/4;
// 		for (uint32_t y = mlx->image->height/2 ; y < mlx->image->height; y++)
// 			mlx_put_pixel(mlx->image, y, x, 0x0FFFFFFF);
// 	}
// 	else if (mlx->player->direction == 'N')
// 	{
// 		for (uint32_t i = mlx->image->width/2; i < mlx->image->width; i++)
// 		{
// 			for (uint32_t j = mlx->image->height/2; j < mlx->image->height; j++)
// 				mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
// 		}
// 		x = 3 * mlx->image->width/4;
// 		for (uint32_t y = mlx->image->height/2 ; y != 0; y--)
// 			mlx_put_pixel(mlx->image, x, y, 0x0FFFFFFF);
// 	}
// 	else if (mlx->player->direction == 'W')
// 	{
// 		for (uint32_t i = mlx->image->width/2; i < mlx->image->width; i++)
// 		{
// 			for (uint32_t j = mlx->image->height/2; j < mlx->image->height; j++)
// 				mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
// 		}
// 		x = 3 * mlx->image->width/4;
// 		for (uint32_t y = mlx->image->height/2 ; y != 0; y--)
// 			mlx_put_pixel(mlx->image, y, x, 0x0FFFFFFF);
// 	}
// }

// printf("x1 ==>%d\n", (mlx->image->width * 3 / 4));
// printf("x2 ==>%f\n", (mlx->image->width * 3 / 4 ) + (cos(mlx->player->rotation) * 25));
// printf("y1 ==>%d\n", mlx->player->y);
// printf("y2 ==>%f\n", mlx->player->y + (sin(mlx->player->rotation) * 25));
