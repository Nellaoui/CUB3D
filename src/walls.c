/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:47 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 12:10:44 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
y = y_start => f(y) = 0;
a * y + b = 0 || - a * y_start = b

y = y_start + line_len => f(y) = tex->height - 1

tex->h - 1 =a*line_len

pixels[i]
*/

uint32_t	get_color_from_texture(mlx_texture_t *texture, float x_percentage, int y, int line_len, int y_start)
{
	int	x_pos = x_percentage * texture->width;
	double	a = ((double)texture->height - 1) / (double)line_len; // f(y) = ay + b;

	int	y_pos = a * (y - y_start);
	int	idx = ((y_pos * texture->width) + x_pos) * texture->bytes_per_pixel;
	uint32_t color = createcolor(texture->pixels[idx], texture->pixels[idx + 1],texture->pixels[idx + 2],texture->pixels[idx + 3]);
	return (color);
}

float	ft_determine_x_percentage(float hit_x, float hit_y)
{
	float x_percentage;
	x_percentage = 0;

	if (hit_x - (int)(hit_x) != 0)
		x_percentage =(hit_x - (int)(hit_x/50)*50)/50;
	else
		x_percentage = (hit_y - (int)(hit_y/50)*50)/50;
	return (x_percentage);
}

void	ft_put_texture(t_cub3d *mlx, t_ray *s, int y, uint32_t x1, uint32_t len2)
{
	int			y_start;
	float		x_percentage;
	y_start = ((mlx->height / 2) - (len2 / 2));

	x_percentage = ft_determine_x_percentage(s->hit_x, s->hit_y);
		if (mlx->player->compas == NORTH)
			mlx_put_pixel(mlx->image, x1, y, get_color_from_texture(mlx->texture[0], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == SOUTH)
			mlx_put_pixel(mlx->image, x1, y, get_color_from_texture(mlx->texture[1], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == WEST)
			mlx_put_pixel(mlx->image, x1, y, get_color_from_texture(mlx->texture[2], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == EAST)
			mlx_put_pixel(mlx->image, x1, y, get_color_from_texture(mlx->texture[3], x_percentage, y, len2, y_start));
}

void	draw_wall(uint32_t x1, uint32_t len2, t_cub3d *mlx, t_ray *s)
{
	uint32_t	y2;
	int			y_start;
	int			y;

	y_start = ((mlx->height / 2) - (len2 / 2));
	y2 = y_start + len2;
	y = y_start * (y_start > 0);
	while (y < y2)
	{
		if (y < 0)
		{
			++y;
			continue;
		}
		else if (y >= mlx->height - 1)
			break;
		ft_put_texture(mlx, s, y, x1, len2);
		y++;
	}
}

void	render_wall(t_cub3d *mlx, t_ray *ray, int i, float	ray_angle)
{
	// double  angle;
	double  projection_height;
	double  projection_distance;
	float	good_ray_distance;
	float	FOV = (60  * (M_PI / 180));
	good_ray_distance = ray->distance * cos(ray_angle - mlx->player->rotation);
	projection_distance = (mlx->width / 2) / tan(FOV / 2);
	projection_height = (TILE_SIZE / good_ray_distance) * projection_distance;
	draw_wall(i, // x
	projection_height // len wa9ef
	,mlx
	,ray);
}
