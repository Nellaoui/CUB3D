/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/09/03 15:45:56 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ft_distance_beteween(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	ft_which_distance(t_cub3d *cub3d, t_ray *s, float ray_angle)
{
	if (s->horizantal_distance < s->vertical_distance)
	{
		s->hit_x = s->hor_wall_hit_x;
		s->hit_y = s->hor_wall_hit_y;
		s->distance = s->horizantal_distance;
		if (ray_angle > 0 && ray_angle < M_PI)
			cub3d->p->compas = SOUTH;
		else
			cub3d->p->compas = NORTH;
	}
	else
	{
		s->hit_x = s->ver_wall_hit_x;
		s->hit_y = s->ver_wall_hit_y;
		s->distance = s->vertical_distance;
		s->was_hit_vertical = true;
		if (ray_angle > M_PI_2 && ray_angle < M_PI + M_PI_2)
			cub3d->p->compas = EAST;
		else
			cub3d->p->compas = WEST;
	}
}

void	ft_count_distance(t_ray *s, t_cub3d *cub3d)
{
	s->horizantal_distance = 0;
	s->vertical_distance = 0;
	if (s->horizantal_founded)
		s->horizantal_distance = ft_distance_beteween(cub3d->p->x,
				cub3d->p->y,
				s->hor_wall_hit_x,
				s->hor_wall_hit_y);
	else
		s->horizantal_distance = MAXFLOAT;
	if (s->vertical_founded)
		s->vertical_distance = ft_distance_beteween(cub3d->p->x,
				cub3d->p->y,
				s->ver_wall_hit_x,
				s->ver_wall_hit_y);
	else
		s->vertical_distance = MAXFLOAT;
}

void	cast_ray(t_cub3d *cub3d)
{
	t_ray	s;
	float	fov;
	float	was_hit_vertical;
	float	ray_angle;
	int		i;

	fov = (60 * (M_PI / 180));
	was_hit_vertical = false;
	ray_angle = cub3d->p->rotation - (fov / 2);
	s.hit_x = 0;
	s.hit_y = 0;
	i = -1;
	while (++i < cub3d->width)
	{
		ray_angle = ft_absolute_angle(ray_angle);
		casting_horizontal(cub3d, ray_angle, &s);
		casting_vertical(cub3d, ray_angle, &s);
		ft_count_distance(&s, cub3d);
		ft_which_distance(cub3d, &s, ray_angle);
		render_wall(cub3d, &s, i, ray_angle);
		ray_angle += (fov / cub3d->width);
	}
}
