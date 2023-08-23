/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/22 21:14:57 by nelallao         ###   ########.fr       */
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
	int dx;
	int dy;
	int steps;
	float x_increment;
	float y_increment;
	float x;
	float y;

	dx = x2 - x1;
	dy = y2 - y1;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_increment = (float)dx / steps;
	y_increment = (float)dy / steps;
	x = x1;
	y = y1;
	for (int i = 0; i <= steps; i++)
	{
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, 0x000000FF);
		x += x_increment;
		y += y_increment;
	}
}

void	draw_player(void *param)
{
	t_cub3d	*mlx;

	mlx = param;
	// draw_carre(mlx->image, mlx->image->width * 3 / 4);
	draw_line(mlx->image, mlx->player->x , mlx->player->y , mlx->player->x + (cos(mlx->player->turn_direction) * mlx->player->x)
	, mlx->player->y + (sin(mlx->player->turn_direction) * mlx->player->y));
	mlx->player->direction = 0;
	mlx->player->move_direction = 0;
	printf("[[%f]]\n", mlx->player->turn_direction);
}

void	update_after_move(void *param)
{
	t_cub3d	*mlx;
	int	move_step ;
	int	x_grid ;
	int	y_grid ;
	int new_x;
	int	new_y;

	move_step = 0;
	mlx = param;
	if (mlx->player->turn_direction >= 0 || mlx->player->turn_direction <= (360 * (M_PI / 180)))
		mlx->player->turn_direction += mlx->player->direction * mlx->player->rotate_speed;
	move_step += mlx->player->move_direction * mlx->player->move_speed;
	new_x = mlx->player->x_map + (cos(mlx->player->turn_direction) * move_step);
	new_y = mlx->player->y_map + (sin(mlx->player->turn_direction) * move_step);
	x_grid = new_x / 50;
	y_grid = new_y / 50;
	if (mlx->holdmap[y_grid][x_grid] != '1')
	{
		mlx->player->x_map = new_x;
		mlx->player->y_map = new_y;
	}
	mlx_delete_image(mlx->mlx, mlx->image);
	render_player(mlx);
}

void	move_on(mlx_key_data_t key, void *prm)
{
	t_cub3d	*mlx;

	mlx	= prm;
	if (key.key == MLX_KEY_A && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->direction = -1;
	else if (key.key == MLX_KEY_D && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->direction = +1;
	else if (key.key == MLX_KEY_UP && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->move_direction = +1;
	else if (key.key == MLX_KEY_DOWN && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		mlx->player->move_direction = -1;

	if (key.key == MLX_KEY_A && key.action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key.key == MLX_KEY_D && key.action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key.key == MLX_KEY_UP && key.action == MLX_RELEASE)
		mlx->player->move_direction = 0;
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_RELEASE)
		mlx->player->move_direction = 0;
		/*-------------------*/
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mlx->mlx);
		exit(1);
	};
	update_after_move(mlx);
}
