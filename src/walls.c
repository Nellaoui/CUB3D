/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:47 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/27 13:49:49 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall(mlx_image_t *image, uint32_t x1, uint32_t y1, uint32_t len1, uint32_t len2,t_cub3d *mlx)
{
	uint32_t	x2;
	uint32_t	y2;
	uint32_t	y;

	x2 = x1 + len1;
	y2 = y1 + len2;
	while (x1 < x2)
	{
		y = y1;
		while (y < y2)
		{
			if(x1 < mlx->width && y < mlx->height)
			{
				mlx_put_pixel(image, x1, y, createcolor(192, 130, 97, 254));
			}
			y++;
		}
		x1++;
	}
}

void    render_wall(t_cub3d *mlx, t_ray *ray, int i, float	ray_angle)
{
	// double  angle;
	double  projection_height;
	double  projection_distance;
	float	good_ray_distance;
	float	FOV = (60  * (M_PI / 180));
	good_ray_distance = ray->distance * cos(ray_angle - mlx->player->rotation);
	projection_distance = (mlx->width / 2) / tan(FOV / 2);
	projection_height = (TILE_SIZE / good_ray_distance) * projection_distance;
	if (projection_height > mlx->height)
		projection_height = mlx->height - 2;
	draw_wall(mlx->image, // image
	i *1, // x
	((mlx->height / 2) - (projection_height / 2)), // y
	1, // len fog
	projection_height // len wa9ef
	,mlx);
}
