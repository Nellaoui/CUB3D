/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/26 14:13:54 by ndahib           ###   ########.fr       */
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

float	ft_distance_beteween(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	cast_ray(t_cub3d *cub3d)
{
	t_ray	s;
	float	FOV = (60  * (M_PI / 180));
	int		i;
	int		column = 0;
	float horizantal_distance = 0;
	float vertical_distance = 0;
	float	hit_x = 0;
	float	hit_y = 0;
	// float	distance = 0;
	float	was_hit_vertical = false;
	// float	was_hit_horizatal = false;
	float	ray_angle = cub3d->player->rotation - (FOV / 2);

	i = 0;
	// ray_angle = ft_absolute_angle(ray_angle);
	while (i < 480)
	{
	ray_angle = ft_absolute_angle(ray_angle);
	casting(cub3d, ray_angle, column , &s);
	casting_vertical(cub3d, ray_angle, column , &s);
	if (s.horizantal_founded)
		horizantal_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s.hor_wall_hit_x, s.hor_wall_hit_y);
	else
		horizantal_distance = MAXFLOAT;
	if (s.vertical_founded)
		vertical_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s.ver_wall_hit_x, s.ver_wall_hit_y);
	else
		vertical_distance = MAXFLOAT;
	if (horizantal_distance < vertical_distance)
	{
		hit_x = s.hor_wall_hit_x;
		hit_y = s.hor_wall_hit_y;
		s.distance = horizantal_distance;
		// was_hit_vertical = false;
	}
	else
	{
		hit_x = s.ver_wall_hit_x;
		hit_y = s.ver_wall_hit_y;
		s.distance = vertical_distance;
		was_hit_vertical = true;
	}
	// printf("horizantal_distance %f\n", horizantal_distance);
	// printf("vertical_distance %f\n", vertical_distance);

		// draw_ray(cub3d->image,
		// 	cub3d->player->x,
		// 	cub3d->player->y,
		// 	s.ver_wall_hit_x,
		// 	s.ver_wall_hit_y);
		draw_ray(cub3d->image,
			cub3d->player->x * 0.2,
			cub3d->player->y * 0.2,
			hit_x * 0.2,
			hit_y * 0.2);
		render_wall(cub3d, &s, i);
		ray_angle += (FOV / 480);
		ray_angle = ft_absolute_angle(ray_angle);
		i++;
		column++;
	}
}
