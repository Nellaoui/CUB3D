/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:33 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 13:55:57 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(void *param)
{
	t_cub3d	*mlx;

	mlx = param;
	mlx->player->move = 0;
}

int	ft_wall_here(float x, float y, t_cub3d *mlx)
{
	if (x < 0 
		|| x > TILE_SIZE * mlx->colons 
		|| y < 0 
		|| y > TILE_SIZE * mlx->rows)
		return (1);
	if (mlx->holdmap[(int)((y + 2) / TILE_SIZE)][(int)((x) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y - 2) / TILE_SIZE)][(int)((x) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y) / TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] != '1'
	&& mlx->holdmap[(int)((y) / TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] != '1')
		return (0);
	return (1);
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
	if (mlx->player->rotation >= 0 || mlx->player->rotation <= (2 * M_PI))
		mlx->player->rotation += (mlx->player->direction 
				* mlx->player->rotate_speed);
	move_step = mlx->player->move * mlx->player->move_speed;
	if (mlx->player->left_right == 1)
		angle = 0;
	if (mlx->player->left_right == -1)
		angle = M_PI / 2;
	new.x = (mlx->player->x + (cos(mlx->player->rotation + angle) * move_step));
	new.y = (mlx->player->y + (sin(mlx->player->rotation + angle) * move_step));
	if (!ft_wall_here(new.x, mlx->player->y, mlx))
		mlx->player->x = new.x;
	if (!ft_wall_here(mlx->player->x, new.y, mlx))
		mlx->player->y = new.y;
	mlx_delete_image(mlx->mlx, mlx->image);
	render_player(mlx);
	cast_ray(mlx);
}

void	move_on(mlx_key_data_t key, void *prm)
{
	t_cub3d	*mlx;

	mlx = prm;
	mouvement_keys(&key, prm);
	release_keys(&key, prm);
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mlx->mlx);
		exit(1);
	}
	update_after_move(mlx);
}
