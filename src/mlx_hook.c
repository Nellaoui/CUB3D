/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/24 15:46:57 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carre(mlx_image_t *image, uint32_t lenght)
{

	for (uint32_t i = image->width / 3; i < lenght; i++)
	{
		for (uint32_t j = image->width / 3; j < lenght; j++)
			mlx_put_pixel(image, i, j, 0x000000FF);
	}
}

void	draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	(void)image;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float x_increment = (float)dx / steps;
	float y_increment = (float)dy / steps;

	float x = x1;
	float y = y1;

	for (int i = 0; i < steps; i++) {
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, 0x000000FF);
		// printf("%f ==\n", x);
		// printf("%f ==\n", y);
		x += x_increment;
		y += y_increment;
	}
}

void	draw_player(void *param)
{
	t_cub3d	*mlx;

	mlx = param;
	// draw_cercle(mlx->image, mlx->player->x , mlx->player->y, 1);
	// draw_cercle(mlx->image, mlx->player->x , mlx->player->y, 2);
	// draw_line(mlx->image, mlx->player->x , mlx->player->y , mlx->player->x + (cos(mlx->player->rotation) * 20)
	// , mlx->player->y + (sin(mlx->player->rotation) * 20));
	mlx->player->direction = 0;
	mlx->player->move = 0;
}

int	ft_wall_here(float x, float y, t_cub3d	*mlx)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || x > WIDGHT || y < 0 || y > HEIGHT)
		return (1);
	x_grid = round(x / TILE_SIZE);
	y_grid = round(y / TILE_SIZE);

	if (mlx->holdmap[y_grid][x_grid] != '1')
		return (0);
	return (1);
}

double	ft_absolute_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, (2 * M_PI));
	if (ray_angle < 0)
		ray_angle += (2 * M_PI);
	return (ray_angle) ;
}

void	casting(t_cub3d *mlx , double ray_angle, int cloumn	,t_ray *s)
{
	(void)cloumn;
	double	x_inter = 0;
	double	y_inter = 0;
	float	x_step = 0;
	float	y_step = 0;
	float	right = 0;
	float	down = 0;
	float	left = 0;
	float	up = 0;
	float	founded	= false;
	float	wall_hit_x = 0;
	float	wall_hit_y= 0;

	s->point_wall_x = 0;
	s->point_wall_y = 0;
	s->distance = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		down = true;
	up = !down;
	if (ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI))
		right = true;
	left = !right;
	y_inter = round(mlx->player->y  / TILE_SIZE) * TILE_SIZE;
	if (down)
		y_inter += TILE_SIZE;
	x_inter = mlx->player->x + (y_inter - mlx->player->y) / tan(ray_angle);
	y_step = TILE_SIZE;
	if (up)
		y_step *= (-1);
	x_step = TILE_SIZE / tan(ray_angle);
	if (left && x_step > 0)
		x_step *= -1;
	if (right && x_step < 0)
		x_step *= -1;

	s->next_horzintal_x = x_inter;
	s->next_horzintal_y = y_inter;
	if (up)
		s->next_horzintal_y--;
	while (s->next_horzintal_x >= 0 && s->next_horzintal_x <= WIDGHT && s->next_horzintal_y >= 0 && s->next_horzintal_y <= HEIGHT)
	{
		if (ft_wall_here(s->next_horzintal_x, s->next_horzintal_y, mlx))
		{
			founded = true;
			wall_hit_x = s->next_horzintal_x;
			wall_hit_y = s->next_horzintal_y;
			break;
		}
		else
			s->next_horzintal_x += x_step;
			s->next_horzintal_y += y_step;
	}
}

void	update_after_move(void *param)
{
	t_cub3d	*mlx;
	int	move_step ;
	float new_x;
	float new_y;

	move_step = 0;
	mlx = param;
	// if (mlx->player->rotation >= 0 || mlx->player->rotation <= (360 * (M_PI / 180)))
		mlx->player->rotation += (mlx->player->direction * mlx->player->rotate_speed);
	move_step = mlx->player->move * mlx->player->move_speed;

	new_x = (mlx->player->x + (cos(mlx->player->rotation) * move_step));
	new_y = (mlx->player->y + (sin(mlx->player->rotation) * move_step));

	if (!ft_wall_here(new_x, new_y, mlx))
	{
		mlx->player->x = new_x;
		mlx->player->y = new_y;
	}
	mlx_delete_image(mlx->mlx, mlx->image);
	render_player(mlx);
	// casting(mlx);
	cast_ray(mlx);
}

void	move_on(mlx_key_data_t key, void *prm)
{
	t_cub3d	*mlx;

	mlx	= prm;
	if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)  && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->direction = -1;
	else if ((key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D) && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->direction = +1;
	else if (key.key == MLX_KEY_W && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->move = +1;
	else if (key.key == MLX_KEY_S && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->move = -1;
	if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)  && key.action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if ((key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D) && key.action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key.key == MLX_KEY_W && key.action == MLX_RELEASE)
		mlx->player->move = 0;
	else if (key.key == MLX_KEY_S && key.action == MLX_RELEASE)
		mlx->player->move = 0;
		/*-------------------*/
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mlx->mlx);
		exit(1);
	}
	update_after_move(mlx);
}
