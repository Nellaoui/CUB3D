/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/27 13:44:39 by nelallao         ###   ########.fr       */
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
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, createcolor(255, 252, 50, 50));
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
	// float	was_hit_vertical;
	// float	was_hit_horizatal;
	float	ray_angle = cub3d->player->rotation - (FOV / 2);

	int a  = cub3d->width;
	i = 0;
	// ray_angle = ft_absolute_angle(ray_angle);
	while (i < a)// cub3d->width)
	{
	ray_angle = ft_absolute_angle(ray_angle);
	casting(cub3d, ray_angle, column , &s);
	casting_vertical(cub3d, ray_angle, column , &s);
	if (s.horizantal_founded)
		horizantal_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s.hor_wall_hit_x, s.hor_wall_hit_y);
	else
		horizantal_distance = 500; // MAXFLOAT
	if (s.vertical_founded)
		vertical_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s.ver_wall_hit_x, s.ver_wall_hit_y);
	else
		vertical_distance = 500; // MAXFLOAT
	if ((int)horizantal_distance == (int)vertical_distance)
	{
		s.distance = horizantal_distance;
		hit_x = s.ver_wall_hit_x;
		hit_y = s.ver_wall_hit_y;
	}
	else if (horizantal_distance < vertical_distance)
	{
		hit_x = s.hor_wall_hit_x;
		hit_y = s.hor_wall_hit_y;
		s.distance = horizantal_distance;
	}
	else
	{
		// printf("{vertical_distance}\n");
		hit_x = s.ver_wall_hit_x;
		hit_y = s.ver_wall_hit_y;
		s.distance = vertical_distance;
		// was_hit_vertical = true;
	}
		draw_ray(cub3d->image,
			cub3d->player->x * CAST,
			cub3d->player->y * CAST,
			hit_x * CAST,
			hit_y * CAST);
		render_wall(cub3d, &s, i, ray_angle);
		ray_angle += (FOV / a);
		ray_angle = ft_absolute_angle(ray_angle);
		i++;
		column++;
	}
}
