/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:47 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/26 13:59:02 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall(mlx_image_t *image, uint32_t x1, uint32_t y1, uint32_t len1, uint32_t len2)
{
	uint32_t	x2;
	uint32_t	y2;
	uint32_t	y;

	x2 = x1 + len1;
	y2 = y1 + len2;
	while (x1 < x2)
	{
		y = y1;
		while (y <  y2)
		{
			mlx_put_pixel(image, x1, y, createcolor(255, 255, 255, 255));
			y++;
		}
		x1++;
	}	
}

void    render_wall(t_cub3d *mlx, t_ray *ray, int i)
{
	double  angle;
	double  projection_height;
	double  projection_distance;

	angle = (30 * (M_PI / 180));
	projection_distance = (480 / 2) / tan(angle);
	// ray->distance = ray->distance *  cos(ray->ray_angle - mlx->player->rotation);
	printf("[%f]\n", ray->distance);
	projection_height = (TILE_SIZE / ray->distance) * projection_distance;
	draw_wall(mlx->image, i * 2, ((mlx->height / 2) - (projection_height / 2)), 2, projection_height);
}