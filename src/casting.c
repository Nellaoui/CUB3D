/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:58:37 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 19:08:01 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	casting_horizontal(t_cub3d *mlx, double ray_angle, t_ray *s)
{
	t_casting	c;

	ft_initialize_cast(&c, s);
	ft_hor_inter(&c, ray_angle, mlx, s);
	while (s->next_horzintal_x >= 0 && s->next_horzintal_x <= TILE_SIZE
		* mlx->colons && s->next_horzintal_y >= 0
		&& s->next_horzintal_y <= s->next_horzintal_y <= TILE_SIZE * mlx->rows)
	{
		if (ft_wall_here_a(s->next_horzintal_x,
				s->next_horzintal_y - c.up,
				mlx))
		{
			s->horizantal_founded = true;
			s->hor_wall_hit_x = s->next_horzintal_x;
			s->hor_wall_hit_y = s->next_horzintal_y;
			break ;
		}
		else
		{
			s->next_horzintal_x += c.x_step;
			s->next_horzintal_y += c.y_step;
		}
	}
}

void	casting_vertical(t_cub3d *mlx, double ray_angle, t_ray *s)
{
	t_casting	c;

	s->ver_wall_hit_x = 0;
	s->ver_wall_hit_y = 0;
	s->vertical_founded = false;
	s->distance = 0;
	c.ver_y_step = 0;
	ft_ver_inter(ray_angle, mlx, &c);
	s->next_vertical_y = c.ver_y_inter;
	s->nx_vert_x = c.ver_x_inter;
	while (s->nx_vert_x >= 0 && s->nx_vert_x <= TILE_SIZE * mlx->colons
		&& s->next_vertical_y >= 0 && s->next_vertical_y <= TILE_SIZE
		* mlx->rows)
	{
		if (ft_wall_here_a(s->nx_vert_x - c.ver_left, s->next_vertical_y, mlx))
		{
			s->vertical_founded = true;
			s->ver_wall_hit_x = s->nx_vert_x;
			s->ver_wall_hit_y = s->next_vertical_y;
			break ;
		}
		else
			s->nx_vert_x += c.ver_x_step;
		s->next_vertical_y += c.ver_y_step;
	}
}

void	ft_hor_inter(t_casting *c, float angle, t_cub3d *mlx, t_ray *s)
{
	if (angle > 0 && angle < M_PI)
		c->down = true;
	c->up = !c->down;
	if (angle < M_PI_2 || angle > (3 * M_PI_2))
		c->right = true;
	c->left = !c->right;
	if (c->down)
		c->y_inter = round((mlx->p->y / TILE_SIZE) + 1) * TILE_SIZE;
	else if (c->up)
		c->y_inter = round((mlx->p->y / TILE_SIZE)) * TILE_SIZE;
	c->x_inter = mlx->p->x + (c->y_inter - mlx->p->y) / tan(angle);
	c->y_step = TILE_SIZE;
	if (c->up)
		c->y_step *= (-1);
	c->x_step = TILE_SIZE / tan(angle);
	if (c->left && c->x_step > 0)
		c->x_step *= -1;
	if (c->right && c->x_step < 0)
		c->x_step *= -1;
	s->next_horzintal_x = c->x_inter;
	s->next_horzintal_y = c->y_inter;
}

void	ft_ver_inter(float r, t_cub3d *mlx, t_casting *c)
{
	c->ver_down = 0;
	c->ver_up = 0;
	c->ver_right = 0;
	c->ver_left = 0;
	c->ver_x_inter = 0;
	c->ver_y_inter = 0;
	c->ver_x_step = 0;
	if (r > 0 && r < M_PI)
		c->ver_down = true;
	c->ver_up = !c->ver_down;
	if (r < M_PI_2 || r > (3 * M_PI_2))
		c->ver_right = true;
	c->ver_left = !c->ver_right;
	c->ver_x_inter = (int)(mlx->p->x / TILE_SIZE) * TILE_SIZE;
	if (c->ver_right)
		c->ver_x_inter += TILE_SIZE;
	c->ver_y_inter = mlx->p->y + (c->ver_x_inter - mlx->p->x) * tan(r);
	c->ver_x_step = TILE_SIZE;
	if (c->ver_left)
		c->ver_x_step *= (-1);
	c->ver_y_step = TILE_SIZE * tan(r);
	if (c->ver_up && c->ver_y_step > 0)
		c->ver_y_step *= -1;
	if (c->ver_down && c->ver_y_step < 0)
		c->ver_y_step *= -1;
}

void	update_after_move(void *param)
{
	t_cub3d			*mlx;
	t_coordinate	new;
	int				move_step;
	float			angle;

	mlx = param;
	angle = 0;
	move_step = 0;
	if (mlx->p->rotation >= 0 || mlx->p->rotation <= (2 * M_PI))
		mlx->p->rotation += (mlx->p->direction
				* mlx->p->rotate_speed);
	move_step = mlx->p->move * mlx->p->move_speed;
	if (mlx->p->left_right == 1)
		angle = 0;
	if (mlx->p->left_right == -1)
		angle = M_PI / 2;
	new.x = (mlx->p->x + (cos(mlx->p->rotation + angle) * move_step));
	new.y = (mlx->p->y + (sin(mlx->p->rotation + angle) * move_step));
	if (!ft_wall_here(new.x, mlx->p->y, mlx))
		mlx->p->x = new.x;
	if (!ft_wall_here(mlx->p->x, new.y, mlx))
		mlx->p->y = new.y;
	mlx_delete_image(mlx->mlx, mlx->image);
	render_p(mlx);
	cast_ray(mlx);
}
