/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:46:50 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 15:02:32 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carr(mlx_image_t *img, uint32_t color, t_coordinate a)
{
	uint32_t	lenght_x;
	uint32_t	lenght_y;
	uint32_t	y;

	lenght_x = a.x + (TILE_SIZE - 1) * CAST;
	lenght_y = a.y + (TILE_SIZE - 1) * CAST;
	while (a.x < lenght_x)
	{
		y = a.y;
		while (y < lenght_y)
		{
			mlx_put_pixel(img, (uint32_t)a.x, (uint32_t)y, color);
			y++;
		}
		(a.x)++;
	}
}

void	draw_c_f(t_cub3d *s)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < s->height / 2)
	{
		x = 0;
		while (x < s->width)
		{
			mlx_put_pixel(s->image, x, y, createcolor(s->c_st, s->c_nd, s->c_rd, 200));
			x++;
		}
		y++;
	}
	y = s->height / 2;
	while (y < s->height)
	{
		x = 0;
		while (x < s->width)
		{
			mlx_put_pixel(s->image, x, y, createcolor(s->f_st, s->f_nd, s->f_rd, 200));
			x++;
		}
		y++;
	}
}

void	render_map(t_cub3d *mlx_lib)
{
	int				i;
	size_t			j;
	uint32_t		color;
	t_coordinate	start_point;

	i = -1;
	while (++i < mlx_lib->rows)
	{
		j = -1;
		while (++j < ft_strlen(mlx_lib->holdmap[i]))
		{
			if (mlx_lib->holdmap[i][j] == '1')
				color = createcolor(255, 0, 0, 255);
			else if (mlx_lib->holdmap[i][j] == ' ')
				continue ;
			else 
				color = createcolor(255, 255, 255, 255);
			start_point.x = TILE_SIZE * j * CAST;
			start_point.y = TILE_SIZE * i * CAST;
			draw_carr(mlx_lib->image, color, start_point);
		}
	}
	if (mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0))
		ft_putstr_fd("error : puting map in window\n", 2);
}

void	render_player(t_cub3d *mlx_lib)
{
	uint32_t	width;
	uint32_t	height;

	width = TILE_SIZE * mlx_lib->colons;
	height = TILE_SIZE * mlx_lib->rows;
	mlx_lib->image = mlx_new_image(mlx_lib->mlx, width, height);
	if (!mlx_lib->image)
		ft_putstr_fd("error in creaitin new_image\n", 2);
	mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0);
	draw_player(mlx_lib);
	// /cast_ray(mlx_lib);
	mlx_key_hook(mlx_lib->mlx, move_on, mlx_lib);
}
