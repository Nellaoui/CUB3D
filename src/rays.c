/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/24 22:17:53 by ndahib           ###   ########.fr       */
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

	for (int i = 0; i < steps; i++)
	{
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, createcolor(255, 252, 127, 1));
		x += x_increment;
		y += y_increment;
	}
}

void	cast_ray(t_cub3d *cub3d)
{
	t_ray s;
	float FOV = (60  * (M_PI / 180));
	int	i;
	int	column = 0;
	float	ray_angle = cub3d->player->rotation - (FOV / 2);
	ray_angle = ft_absolute_angle(ray_angle);
	i = 0;
	// while (i < 480)
	// {
		casting(cub3d, ray_angle, column , &s);
		draw_ray(cub3d->image,
			cub3d->player->x,
			cub3d->player->y,
			s.next_horzintal_x,
			s.next_horzintal_y);
		ray_angle += (FOV / 480);
		ray_angle = ft_absolute_angle(ray_angle);
	// 	i++;
	// 	column++;
	// }
}
