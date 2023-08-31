/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:34:41 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/31 15:56:31 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mouvement_keys(mlx_key_data_t *key, t_cub3d *mlx)
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
		{
		mlx->player->move = +1;
		}
	else if (key->key == MLX_KEY_S
		&& (key->action == MLX_PRESS || key->action == MLX_REPEAT))
		mlx->player->move = -1;
}

void	release_keys(mlx_key_data_t *key, t_cub3d *mlx)
{
	if (key->key == MLX_KEY_LEFT && key->action == MLX_RELEASE)
		mlx->player->direction = 0;
	else if (key->key == MLX_KEY_A && key->action == MLX_RELEASE)
		mlx->player->left_right = 1;
	else if (key->key == MLX_KEY_D && key->action == MLX_RELEASE)
		mlx->player->left_right = 1;
	else if (key->key == MLX_KEY_RIGHT && key->action == MLX_RELEASE)
		mlx->player->direction = 0;
	else
	{
		mlx->player->left_right = 1;
		mlx->player->move = 0;
	}
}
