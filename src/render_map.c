/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:46:50 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/20 11:35:03 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carr(void	*param)
{
	t_cub3d	*mlx_lib;

	mlx_lib = param;
	for (uint16_t i = 0; i < 50; i++)
	{
		for (uint16_t j = 0; j < 50; j++)
			mlx_put_pixel(mlx_lib->image, i, j, 0xFFFFFFFF);
	}
}

void	put_image_of_map(t_cub3d *mlx_lib, uint32_t i, uint32_t j, uint32_t size)
{
	if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx, size, size)))
		ft_putstr_fd("error in creaitin new_image\n", 2);
	mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, i, j);
	mlx_loop_hook(mlx_lib->mlx, draw_carr, (mlx_lib));
}

void	render_map(t_cub3d *mlx_lib)
{
	u_int32_t	color;
	int			i;
	int			j;

	color = 0;
	i = -1;
	while (++i < mlx_lib->rows)
	{
		j = -1;
		while (++j < number_of_colons(mlx_lib->holdmap[i]))
		{
			if (mlx_lib->holdmap[i][j] == '0')
				color = createcolor(255, 255, 255, 255);
			else if (mlx_lib->holdmap[i][j] == '1')
				color = createcolor(255, 0, 0, 255);
			if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx,  mlx_lib->tile_x, mlx_lib->tile_y)))
				ft_putstr_fd("error in creaitin new_image\n", 2);
			mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, j * mlx_lib->tile_x, i * mlx_lib->tile_y);
			for (uint16_t i = 0; i < 49; i++)
			{
				for (uint16_t j = 0; j < 49; j++)
					mlx_put_pixel(mlx_lib->image, i, j, color);
			}
		}
	}
}

void	render_player(t_cub3d *mlx_lib)
{
	if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx, 50, 50)))
		ft_putstr_fd("error in creaitin new_image\n", 2);
	mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 50, 400);
	mlx_loop_hook(mlx_lib->mlx, draw_player, mlx_lib);
	mlx_loop_hook(mlx_lib->mlx, move_on, mlx_lib);
}
