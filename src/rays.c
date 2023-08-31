/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 12:55:02 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void    draw_ray(int x0, int y0, int x1, int y1, mlx_image_t *image)
// {
//     int        dx;
//     int        dy;
//     int        i;
//     int        steps;
//     int     x_inc, y_inc;

//     i = 0;
//     dx = x1 - x0;
//     dy = y1 - y0;
//     if (abs(dx) > abs(dy))
//         steps = abs(dx);
//     else
//         steps = abs(dy);
//     x_inc = dx / (float)steps;
//     y_inc = dy / (float)steps;
//     while (i <= steps)
//     {
//         pixel_draw(x0, y0, image, ft_pixel(25, 50, 20, 1));
//         x0 += x_inc;
//         y0 += y_inc;
//         i++;
//     }
// }

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
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, createcolor(255, 0, 255, 10));
		x += x_increment;
		y += y_increment;
	}
}

float	ft_distance_beteween(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	ft_which_distance(t_cub3d *cub3d, t_ray	*s, float	ray_angle)
{
		if (s->horizantal_distance < s->vertical_distance)
		{
			s->hit_x = s->hor_wall_hit_x;
			s->hit_y = s->hor_wall_hit_y;
			s->distance = s->horizantal_distance;
			if (ray_angle > 0 && ray_angle < M_PI)
				cub3d->player->compas = SOUTH;
			else
				cub3d->player->compas = NORTH;
		}
		else
		{
			s->hit_x = s->ver_wall_hit_x;
			s->hit_y = s->ver_wall_hit_y;
			s->distance = s->vertical_distance;
			s->was_hit_vertical = true;
			if (ray_angle > M_PI_2 && ray_angle < M_PI + M_PI_2)
				cub3d->player->compas = EAST;
			else
				cub3d->player->compas = WEST;
		}
}

void	ft_count_distance(t_ray	*s, t_cub3d *cub3d)
{
	s->horizantal_distance = 0;
	s->vertical_distance   = 0;
	if (s->horizantal_founded)
		s->horizantal_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s->hor_wall_hit_x, s->hor_wall_hit_y);
	else
		s->horizantal_distance = MAXFLOAT;
	if (s->vertical_founded)
		s->vertical_distance = ft_distance_beteween(cub3d->player->x, cub3d->player->y, s->ver_wall_hit_x, s->ver_wall_hit_y);
	else
		s->vertical_distance = MAXFLOAT;

}

void	cast_ray(t_cub3d *cub3d)
{
	t_ray	s;
	float	FOV = (60  * (M_PI / 180));
	float	was_hit_vertical;
	float	ray_angle;
	int	i;

	was_hit_vertical = false;
	ray_angle = cub3d->player->rotation - (FOV / 2);
	s.hit_x = 0;
	s.hit_y = 0;
	i = 0;
	while (i < cub3d->width)// cub3d->width)
	{
		ray_angle = ft_absolute_angle(ray_angle);
		casting(cub3d, ray_angle , &s);
		casting_vertical(cub3d, ray_angle, &s);
		ft_count_distance(&s, cub3d);
		ft_which_distance(cub3d, &s, ray_angle);
		draw_ray(cub3d->image, cub3d->player->x * cub3d->scale_width, cub3d->player->y * cub3d->scale_height, s.hit_x * cub3d->scale_width, s.hit_y * cub3d->scale_height);
		render_wall(cub3d, &s, i, ray_angle);
		ray_angle += (FOV / cub3d->width);
		i++;
	}
}
