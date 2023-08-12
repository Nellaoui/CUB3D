/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/12 12:51:41 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(void *param)
{
	mlx_image_t	*image;
	int			i;
	const float pi = 3.14;

	image = param;
	i = 0;
	while (i < 360)
	{
		uint32_t x = image->height/2 * cos((i * pi / 180));
		uint32_t y = image->height/2 * sin((i * pi / 180));
		mlx_put_pixel(image, image->height/2 + x, image->width/2 + y, 0xFFFFFF);
		i += 1;
	}
}

void	move_on(void *prm)
{
	t_cub3d	*mlx_lib;

	mlx_lib	= prm;
	if (mlx_is_key_down(mlx_lib->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx_lib->mlx);
	if (mlx_is_key_down(mlx_lib->mlx, MLX_KEY_UP))
		mlx_lib->image->instances[0].y -= 3;
	if (mlx_is_key_down(mlx_lib->mlx, MLX_KEY_DOWN))
		mlx_lib->image->instances[0].y += 3;
	if (mlx_is_key_down(mlx_lib->mlx, MLX_KEY_LEFT))
		mlx_lib->image->instances[0].x -= 3;
	if (mlx_is_key_down(mlx_lib->mlx, MLX_KEY_RIGHT))
		mlx_lib->image->instances[0].x += 3;
}