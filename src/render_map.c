/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:46:50 by ndahib            #+#    #+#             */
/*   Updated: 2023/09/02 13:00:45 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_carr(t_cub3d *cub3d, uint32_t color, t_coordinate a)
{
	uint32_t	lenght_x;
	uint32_t	lenght_y;
	uint32_t	y;

	lenght_x = a.x + (TILE_SIZE -1) * cub3d->scale_width;
	lenght_y = a.y + (TILE_SIZE - 1) * cub3d->scale_height;
	while (a.x < lenght_x)
	{
		y = a.y;
		while (y < lenght_y)
		{
			mlx_put_pixel(cub3d->image, (uint32_t)a.x, (uint32_t)y, color);
			y++;
		}
		(a.x)++;
	}
}

void	draw_c(t_cub3d *s)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < s->height / 2)
	{
		x = 0;
		while (x < s->width)
		{
			mlx_put_pixel(s->image, x, y,
				createcolor(s->c_st, s->c_nd, s->c_rd, 200));
			x++;
		}
		y++;
	}
}

void	draw_f(t_cub3d *s)
{
	uint32_t	x;
	uint32_t	y;

	y = s->height / 2;
	while (y < s->height)
	{
		x = 0;
		while (x < s->width)
		{
			mlx_put_pixel(s->image, x, y,
				createcolor(s->f_st, s->f_nd, s->f_rd, 200));
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
			start_point.x = TILE_SIZE * j * mlx_lib->scale_width;
			start_point.y = TILE_SIZE * i * mlx_lib->scale_height;
			draw_carr(mlx_lib, color, start_point);
		}
	}
	if (mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0) == -1)
		ft_putstr_fd("Error\n", 2);
}

void	render_p(t_cub3d *mlx_lib)
{
	// uint32_t	width;
	// uint32_t	height;

	// width = TILE_SIZE * mlx_lib->colons;
	// height = TILE_SIZE * mlx_lib->rows;
	mlx_lib->image = mlx_new_image(mlx_lib->mlx, WIDGHT, HEIGHT);
	if (!mlx_lib->image)
	{
		mlx_terminate(mlx_lib->mlx);
		ft_putstr_fd("error in creaitin new_image\n", 2);
		exit(1);
	}
	mlx_image_to_window(mlx_lib->mlx, mlx_lib->image, 0, 0);
	// draw_c(mlx_lib);
	// draw_f(mlx_lib);
	cast_ray(mlx_lib);
	mlx_key_hook(mlx_lib->mlx, move_on, mlx_lib);
}
