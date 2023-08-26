/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:46:50 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/25 11:10:59 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carr(mlx_image_t *image, u_int32_t	color, uint32_t start_x, uint32_t start_y)
{
	uint32_t	lenght_x;
	uint32_t	lenght_y;
	uint32_t	y;

	lenght_x = start_x + 9;
	lenght_y = start_y + 9;
	while (start_x < lenght_x)
	{
		y = start_y;
		while (y < lenght_y)
		{
			mlx_put_pixel(image, start_x, y, color);
			y++;
		}
		start_x++;
	}
}

void	render_map(t_cub3d *mlx_lib)
{
	uint32_t	color;
	int			i;
	int			j;

	color = 0;
	i = -1;
	if (!(mlx_lib->image = mlx_new_image(mlx_lib->mlx,  mlx_lib->width, mlx_lib->height)))
		ft_putstr_fd("error in creaitin new_image\n", 2);
	while (++i < mlx_lib->rows)
	{
		j = -1;
		while (++j < number_of_colons(mlx_lib->holdmap[i]))
		{
			if (mlx_lib->holdmap[i][j] == '0' || (mlx_lib->holdmap[i][j] != '1'))
				color = createcolor(255, 255, 255, 255);
			else if (mlx_lib->holdmap[i][j] == '1')
				color = createcolor(255, 0, 0, 255);
			draw_carr(mlx_lib->image, color, 10 * j, 10 * i);
		}
	}
	if (mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0))
		ft_putstr_fd("error : putin map in window\n", 2);
}

void	draw_cercle(mlx_image_t *image, int center_x, int center_y, int radius)
{
	int x = 0;
	int y = 0;
	int angle = 0;

	while (angle < 360)
	{
		x = center_x + (radius * cos(angle * M_PI / 180));
		y = center_y + (radius * sin(angle * M_PI / 180));
		mlx_put_pixel(image, x, y, createcolor(200, 25, 175, 255));
		angle++;
	}
}

void	render_player(t_cub3d *mlx)
{
	if (!(mlx->image = mlx_new_image(mlx->mlx, mlx->width, mlx->height)))
		ft_putstr_fd("error in creaitin new_image\n", 2);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	draw_player(mlx);
	mlx_key_hook(mlx->mlx, move_on, mlx);
}
