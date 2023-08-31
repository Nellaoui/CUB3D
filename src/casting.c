/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:02:19 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 15:01:55 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	ft_wall_here_a(float x, float y, t_cub3d *mlx)
// {
// 	if (x < 0 
// 		|| x > mlx->tile_x * mlx->colons
// 		|| y < 0
// 		|| y > mlx->tile_y * mlx->rows)
// 		return (1);
// 	if (mlx->holdmap[(int)((y) / TILE_SIZE)][(int)((x) / TILE_SIZE)] != '1')
// 		return (0);
// 	return (1);
// }

// void	casting_loop_horinz(t_cub3d *mlx, t_union *u, t_direction d, t_ray *s)
// {
// 	float	nexthorzx;
// 	float	nexthorzy;

// 	nexthorzx = u->inter.x;
// 	nexthorzy = u->inter.y;
// 	while (nexthorzx >= 0 && nexthorzx <= mlx->tile_x * mlx->colons 
// 		&& nexthorzy >= 0 && nexthorzy <= s->next_horzintal_y
// 		&& s->next_horzintal_y <= mlx->tile_y * mlx->rows)
// 	{
// 		if (ft_wall_here_a(nexthorzx, nexthorzy - d.up, mlx))
// 		{
// 			s->horizantal_founded = true;
// 			s->hor_wall_hit_x = nexthorzx;
// 			s->hor_wall_hit_y = nexthorzy;
// 			break ;
// 		}
// 		else
// 		{
// 			nexthorzx += u->step.x;
// 			nexthorzy += u->step.y;
// 		}
// 	}
// }

// void	casting_loop_vertical(t_cub3d *mlx, t_union *u, t_direction d, t_ray *s)
// {
// 	s->next_vertical_y = u->inter.y;
// 	s->next_vertical_x = u->inter.x;
// 	while (s->next_vertical_x >= 0 
// 		&& s->next_vertical_x <= TILE_SIZE * mlx->colons 
// 		&& s->next_vertical_y >= 0 
// 		&& s->next_vertical_y <= TILE_SIZE * mlx->rows)
// 	{
// 		if (ft_wall_here_a(s->next_vertical_x - d.left,
// 				s->next_vertical_y, mlx))
// 		{
// 			s->vertical_founded = true;
// 			s->ver_wall_hit_x = s->next_vertical_x;
// 			s->ver_wall_hit_y = s->next_vertical_y;
// 			break ;
// 		}
// 		else
// 		{
// 			s->next_vertical_x += u->step.x;
// 			s->next_vertical_y += u->step.y;
// 		}
// 	}
// }

// void	casting_horizontal(t_cub3d *mlx, double ray_angle, t_ray *s)
// {
// 	t_union			u;
// 	t_direction		direction;

// 	if (ray_angle > 0 && ray_angle < M_PI)
// 		direction.down = true;
// 	direction.up = !direction.down;
// 	if (ray_angle < M_PI_2 || ray_angle > (3 * M_PI_2))
// 		direction.right = true;
// 	direction.left = !direction.right;
// 	if (direction.down)
// 		u.inter.y = round((mlx->player->y / TILE_SIZE) + 1) * TILE_SIZE;
// 	else if (direction.up)
// 		u.inter.y = round((mlx->player->y / TILE_SIZE)) * TILE_SIZE;
// 	u.inter.x = mlx->player->x + (u.inter.y - mlx->player->y) / tan(ray_angle);
// 	u.step.y = TILE_SIZE;
// 	if (direction.up)
// 		u.step.y *= (-1);
// 	u.step.x = TILE_SIZE / tan(ray_angle);
// 	if (direction.left && u.step.x > 0)
// 		u.step.x *= -1;
// 	if (direction.right && u.step.x < 0)
// 		u.step.x *= -1;
// 	casting_loop_horinz(mlx, &u, direction, s);
// }

// void	casting_vertical(t_cub3d *mlx, double ray_angle, t_ray *s)
// {
// 	t_union			u;
// 	t_direction		direction;

// 	if (ray_angle > 0 && ray_angle < M_PI)
// 		direction.down = true;
// 	direction.up = !direction.down;
// 	if (ray_angle < M_PI_2 || ray_angle > (3 * M_PI_2))
// 		direction.right = true;
// 	direction.left = !direction.right;
// 	u.inter.x = (int)(mlx->player->x / TILE_SIZE) * TILE_SIZE;
// 	if (direction.right)
// 		u.inter.x += TILE_SIZE;
// 	u.inter.y = mlx->player->y + (u.inter.x - mlx->player->x) * tan(ray_angle);
// 	u.step.x = TILE_SIZE;
// 	if (direction.left)
// 		u.step.x *= (-1);
// 	u.step.y = TILE_SIZE * tan(ray_angle);
// 	if (direction.up && u.step.y > 0)
// 		u.step.y *= (-1);
// 	if (direction.down && u.step.y < 0)
// 		u.step.y *= (-1);
// 	casting_loop_vertical(mlx, &u, direction, s);
// }
