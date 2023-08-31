/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:46:50 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 13:00:35 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carr(t_cub3d *cub3d, u_int32_t	color, uint32_t start_x, uint32_t start_y)
{
	uint32_t	lenght_x;
	uint32_t	lenght_y;
	uint32_t	y;

	lenght_x = start_x + 48 * cub3d->scale_height;
	lenght_y = start_y + 48 * cub3d->scale_height;
	while (start_x < lenght_x)
	{
		y = start_y;
		while (y < lenght_y)
		{
			mlx_put_pixel(cub3d->image, start_x, y, color);
			y++;
		}
		start_x++;
	}
}
void draw_c_f(t_cub3d *mlx)
{
	int	x;
	int y;

	y = 0;

	while(y < mlx->height / 2)
	{
		x = 0;
		while (x < mlx->width)
		{
			mlx_put_pixel(mlx->image, x, y , createcolor(mlx->c_st, mlx->c_nd, mlx->c_rd, 200));
			x++;
		}
		y++;
	}
	y  = mlx->height / 2;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			mlx_put_pixel(mlx->image, x, y , createcolor(mlx->f_st, mlx->f_nd, mlx->f_rd, 200));
			x++;
		}
		y++;
	}
}


void	render_map(t_cub3d *mlx_lib)
{
	uint32_t	color;
	int			i;
	int			j;

	color = 0;
	i = -1;
	if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx,  mlx_lib->tile_x * mlx_lib->colons, mlx_lib->tile_y * mlx_lib->rows)))
		ft_putstr_fd("Error\n somthing went worng with image\n", 2);
	draw_c_f(mlx_lib);
	while (++i < mlx_lib->rows)
	{
		j = -1;
		while (++j < number_of_colons(mlx_lib->holdmap[i]))
		{
			if (mlx_lib->holdmap[i][j] == '0')
				color = createcolor(0, 255, 255, 255);
			else if (mlx_lib->holdmap[i][j] == '1')
				color = createcolor(255, 0, 0, 255);
			else
				color = createcolor(255, 0, 0, 0);
			draw_carr(mlx_lib, color, mlx_lib->tile_x * j * mlx_lib->scale_height, mlx_lib->tile_y * i * mlx_lib->scale_height);
		}
	}
	if (mlx_image_to_window(mlx_lib->mlx, mlx_lib->image,0,0))
		ft_putstr_fd("Error\n\n", 2);
}



void	render_player(t_cub3d *mlx_lib)
{
	if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx, mlx_lib->tile_x * mlx_lib->colons, mlx_lib->tile_y * mlx_lib->rows)))
		ft_putstr_fd("Error\n somthing went wrong with the player\n", 2);
	mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0);
	draw_player(mlx_lib);
	cast_ray(mlx_lib);
	mlx_key_hook(mlx_lib->mlx, move_on, mlx_lib);
}
