/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 10:54:32 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(void *param)
{
	t_cub3d	*mlx;
	uint32_t	x;

	mlx = param;
	if (mlx->player->direction == 'S')
	{
		for (uint32_t i = 0; i < mlx->image->width/2; i++)
		{
			for (uint32_t j = 0; j < mlx->image->height/2; j++)
			mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
		}
		x = mlx->image->width/4;
		for (uint32_t y = mlx->image->height/2 ; y < mlx->image->height; y++)
			mlx_put_pixel(mlx->image, x, y, 0x0FFFFFFF);
	}
	else if (mlx->player->direction == 'E')
	{
		for (uint32_t i = 0; i < mlx->image->width/2; i++)
		{
			for (uint32_t j = 0; j < mlx->image->height/2; j++)
			mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
		}
		x = mlx->image->width/4;
		for (uint32_t y = mlx->image->height/2 ; y < mlx->image->height; y++)
			mlx_put_pixel(mlx->image, y, x, 0x0FFFFFFF);	
	}
	else if (mlx->player->direction == 'N')
	{
		for (uint32_t i = mlx->image->width/2; i < mlx->image->width; i++)
		{
			for (uint32_t j = mlx->image->height/2; j < mlx->image->height; j++)
				mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
		}
		x = 3 * mlx->image->width/4;
		for (uint32_t y = mlx->image->height/2 ; y != 0; y--)
			mlx_put_pixel(mlx->image, x, y, 0x0FFFFFFF);
	}
	else if (mlx->player->direction == 'W')
	{
		for (uint32_t i = mlx->image->width/2; i < mlx->image->width; i++)
		{
			for (uint32_t j = mlx->image->height/2; j < mlx->image->height; j++)
				mlx_put_pixel(mlx->image, i, j, 0x0FFFFFFF);
		}
		x = 3 * mlx->image->width/4;
		for (uint32_t y = mlx->image->height/2 ; y != 0; y--)
			mlx_put_pixel(mlx->image, y, x, 0x0FFFFFFF);		
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