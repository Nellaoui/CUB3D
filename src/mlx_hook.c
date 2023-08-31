/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 19:59:58 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_initialize_cast(t_casting *c, t_ray *s)
{
	c->x_inter = 0;
	c->y_inter = 0;
	c->x_step = 0;
	c->y_step = 0;
	c->right = 0;
	c->down = 0;
	c->left = 0;
	c->up = 0;
	s->hor_wall_hit_x = 0;
	s->hor_wall_hit_y = 0;
	s->horizantal_founded = false;
	s->distance = 0;
}

void	ft_one(t_cub3d	*mlx, mlx_key_data_t *key)
{
	if (key->key == MLX_KEY_LEFT
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
		mlx->player->direction = -1;
	else if (key->key == MLX_KEY_RIGHT
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
		mlx->player->direction = +1;
	else if (key->key == MLX_KEY_A
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
	{
		mlx->player->left_right = -1;
		mlx->player->move = -1;
	}
	else if (key->key == MLX_KEY_D
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
	{
		mlx->player->left_right = -1;
		mlx->player->move = +1;
	}
	else if (key->key == MLX_KEY_W
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
		mlx->player->move = +1;
	else if (key->key == MLX_KEY_S
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
		mlx->player->move = -1;
}

void	ft_two(mlx_key_data_t *key, t_cub3d	*mlx)
{
	if (key->key == MLX_KEY_LEFT && key->action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key->key == MLX_KEY_A && key->action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
	}
	else if (key->key == MLX_KEY_D && key->action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
	}
	else if (key->key == MLX_KEY_W && key->action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
		mlx->player->move = 0;
	}
	else if (key->key == MLX_KEY_S && key->action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
		mlx->player->move = 0;
	}
}

void	move_on(mlx_key_data_t key, void *prm)
{
	t_cub3d	*mlx;

	mlx = prm;
	ft_one(mlx, &key);
	ft_two(&key, mlx);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
		mlx->player->move = 0;
	}
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_RELEASE)
	{
		mlx->player->left_right = 1;
		mlx->player->move = 0;
	}
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(mlx->mlx, mlx->image);
		mlx_close_window(mlx->mlx);
		mlx_terminate(mlx->mlx);
		exit(1);
	}
	update_after_move(mlx);
}

void	draw_player(void *param)
{
	t_cub3d	*mlx;

	mlx = param;
	mlx->player->move = 0;
}
