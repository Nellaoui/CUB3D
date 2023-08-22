/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/22 18:24:46 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ray(mlx_image_t *image, double x1, double y1, double x2, double y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float x_increment = (float)dx / steps;
	float y_increment = (float)dy / steps;

	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++) {
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, createcolor(255, 252, 127, 1));
		x += x_increment;
		y += y_increment;
	}
}

void	cast_ray(t_cub3d *cub3d)
{
	double FOV = (60  * (M_PI / 180));
	double  ray_angle = cub3d->player->turn_direction - (FOV / 2);
	
	for (int i = 0; i < 320; i++)
	{
		draw_ray(cub3d->image, 
			cub3d->player->x,
			cub3d->player->y,
			cub3d->player->x + (cos(ray_angle) * 25),
			cub3d->player->y + (sin(ray_angle) * 25));
		ray_angle += (FOV / 320);
	}
}
