/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:47 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/30 18:41:33 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	render_wall(t_cub3d *mlx, t_ray *ray, int i, float ray_angle, float hit_x, float hit_y, int was_hit_vertical)
// {
// 	double  projection_height;
// 	double  projection_distance;
// 	float	good_ray_distance;
// 	float	FOV = (60  * (M_PI / 180));
// 	good_ray_distance = ray->distance * cos(ray_angle - mlx->player->rotation);
// 	projection_distance = (mlx->width / 2) / tan(FOV / 2);
// 	projection_height = (TILE_SIZE / good_ray_distance) * projection_distance;
// 	draw_wall(mlx->image,
// 	i,
// 	((mlx->height / 2) - (projection_height / 2)),
// 	1,
// 	projection_height,
//     mlx,
//     hit_x , hit_y,was_hit_vertical, ray_angle);
// }