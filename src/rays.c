/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:04:41 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 15:02:05 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	draw_ray(mlx_image_t *image, t_coordinate a1, t_coordinate a2)
// {
// 	int				i;
// 	int				steps;
// 	t_coordinate	delta;
// 	t_coordinate	increment;
// 	t_coordinate	point;

// 	delta.x = a2.x - a1.x;
// 	delta.y = a2.y - a1.y;
// 	if (delta.x >delta.y)
// 		steps = delta.x;
// 	else
// 		steps = delta.y;
// 	increment.x = (float)(delta.x) / steps;
// 	increment.y = (float)(delta.y) / steps;
// 	point.x = a1.x;
// 	point.y = a1.y;
// 	i = -1;
// 	while (++i < steps) 
// 	{
// 		mlx_put_pixel(image, (uint32_t)point.x,
// 			(uint32_t)point.y, createcolor(255, 252, 50, 50));
// 		point.x += increment.x;
// 		point.x += increment.y;
// 	}
// }

// float	ft_distance_beteween(float x1, float y1, float x2, float y2)
// {
// 	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
// }

// float	calculate_distance_horizontal(t_ray *s,t_cub3d *cub3d)
// {
// 	if (s->horizantal_founded)
// 		return (ft_distance_beteween(cub3d->player->x,
// 		cub3d->player->y,
// 		s->hor_wall_hit_x,
// 		s->hor_wall_hit_y));
// 	else
// 		return (MAXFLOAT);	
// }

// float	calculate_distance_vertical(t_ray *s,t_cub3d *cub3d)
// {
// 	if (s->vertical_founded)
// 		return (ft_distance_beteween(cub3d->player->x,
// 		cub3d->player->y,
// 		s->ver_wall_hit_x,
// 		s->ver_wall_hit_y));
// 	else
// 		return (MAXFLOAT);	
// }

// void	compare_distance(t_union *u, t_cub3d *cub3d, t_ray *s)
// {
// 	if (u->distance.y < u->distance.x)
// 	{
// 		u->inter.x = s->hor_wall_hit_x;
// 		u->inter.y = s->hor_wall_hit_y;
// 		s->distance = u->distance.y;
// 		if (u->ray_angle > 0 && u->ray_angle < M_PI)
// 			cub3d->player->compas = SOUTH;
// 		else
// 		cub3d->player->compas = NORTH;
// 	}
// 	else
// 	{
// 		u->inter.x = s->ver_wall_hit_x;
// 		u->inter.y = s->ver_wall_hit_y;
// 		s->distance = u->distance.y;
// 		u->was_hit_vertical = true;
// 		if (u->ray_angle > M_PI_2 && u->ray_angle < M_PI + M_PI_2)
// 			cub3d->player->compas = EAST;
// 		else
// 			cub3d->player->compas = WEST;
// 	}
// }

// void	casting(t_cub3d *cub3d, t_union *u, t_ray *s)
// {
// 	int was_hit_vertical;

// 	was_hit_vertical = false;
// 	casting_horizontal(cub3d, u->ray_angle, s);
//  	casting_vertical(cub3d, u->ray_angle, s);
// 	u->distance.y = calculate_distance_horizontal(s, cub3d);
// 	u->distance.x = calculate_distance_vertical(s, cub3d);
// 	compare_distance(u, cub3d, s);
// }
// void	cast_ray(t_cub3d *cub3d)
// {
// 	uint32_t		i;
// 	t_ray			s;
// 	t_union			u;
// 	t_coordinate	p;

// 	i = -1;
// 	u.ray_angle = cub3d->player->rotation - ((60 / 2) * (M_PI / 180));
// 	while (++i < cub3d->width)
// 	{
// 		u.ray_angle = ft_absolute_angle(u.ray_angle);
// 		casting(cub3d, &u, &s);
// 		p.x = cub3d->player->x * CAST;
// 		p.y = cub3d->player->y * CAST;
// 		u.inter.x = u.inter.x * CAST;
// 		u.inter.y = u.inter.y * CAST;
// 		draw_ray(cub3d->image, p, u.inter);
// 		// render_wall(cub3d, &s, i, ray_angle, was_hit_vertical);
// 		u.ray_angle += ((60 * (M_PI / 180) / cub3d->width));
// 	}		
// }
