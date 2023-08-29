/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:19:47 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/29 23:10:30 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void draw_texture(mlx_t* mlx, mlx_image_t* image, mlx_texture_t* texture)
// {
// 	uint8_t* pixelx;
// 	uint8_t* pixeli;
// 	int		tex_x;
// 	int		tex_y;
// 	int		image_x;
// 	int		image_y;

// 	tex_x = 0;
// 	tex_y = 0;
// 	image_x = 500;
// 	image_y = 10;
// 	for (uint32_t imagse_y = 10; image_y < texture->height; image_y++)
// 	{
// 		pixelx = &texture->pixels[((tex_y * texture->width) + tex_x)* texture->bytes_per_pixel];
// 		pixeli = &image->pixels[((image_y * image->width) + image_x) * texture->bytes_per_pixel];
// 		ft_memmove(pixeli, pixelx, texture->width * texture->bytes_per_pixel);
// 	}
// // }

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

void	draw_wall(mlx_image_t *image, uint32_t x1, __unused uint32_t y1, __unused uint32_t len1, uint32_t len2,t_cub3d *mlx, float hit_x, float hit_y, int was_hit_vertical, float ray_angle)
{
	uint32_t	x2;
	uint32_t	y2;
	int		y_start;
	int		y;
	static int	bo;

	if (bo == 0)
	{
		mlx->texture[0] = mlx_load_png("walls/wall_0.png");
		mlx->texture[1] = mlx_load_png("walls/wall_1.png");
		mlx->texture[2] = mlx_load_png("walls/wall_2.png");
		mlx->texture[3] = mlx_load_png("walls/wall_3.png");
		bo = 1;
	}
	// int compas;
	// int compas1;
	// if (cos(ray_angle) > 0)
	// 	compas = EAST;
	// if (cos(ray_angle) < 0)
	// 	compas = WEST;
	// if (sin(ray_angle) > 0)
	// 	compas = NORTH;
	// if (sin(ray_angle) < 0)
		// compas = SOUTH;
	// printf("sin %f\n", sin(ray_angle));
	// printf("cos %f\n", cos(ray_angle));
	// uint8_t *pixels = loading_wall(mlx->mlx);
	y_start = ((mlx->height / 2) - (len2 / 2));
	y2 = y_start + len2;
	y = y_start * (y_start > 0);
		float x_percentage = 0;

	if (hit_x - (int)(hit_x) != 0)
		x_percentage =(hit_x - (int)(hit_x/50)*50)/50;
	else
		x_percentage = (hit_y - (int)(hit_y/50)*50)/50;
	// printf("x->%.10f\n", hit_x);
	// printf("0->%.10f\n", hit_x - (int)(hit_x/50));
	// printf("1->%.10f\n", (hit_x - (int)(hit_x/50)*50));
	// printf("1->%.10f\n", (hit_x - (int)(hit_x)/50*50));
	// printf("3->%.10f\n", (hit_x - (int)(hit_x/50)*50)/50);
	while (y < y2)
	{
		if (y < 0)
		{
			++y;
			continue;
		}
		else if (y >= mlx->height)
			break;
		// mlx_put_pixel(image, x1, y, get_color_from_texture(mlx->texture[0], x_percentage, y, len2, y_start));
		if (mlx->player->compas == NORTH)
			mlx_put_pixel(image, x1, y, get_color_from_texture(mlx->texture[0], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == SOUTH)
			mlx_put_pixel(image, x1, y, get_color_from_texture(mlx->texture[1], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == WEST)
			mlx_put_pixel(image, x1, y, get_color_from_texture(mlx->texture[2], x_percentage, y, len2, y_start));
		else if (mlx->player->compas == EAST)
			mlx_put_pixel(image, x1, y, get_color_from_texture(mlx->texture[3], x_percentage, y, len2, y_start));
		y++;
	}
	static int b;
	// printf("%d || %d\n", compas, b++);
	// printf("%d\n", compas1);
}

void	render_wall(t_cub3d *mlx, t_ray *ray, int i, float	ray_angle, float hit_x, float hit_y, int was_hit_vertical)
{
	// double  angle;
	double  projection_height;
	double  projection_distance;
	float	good_ray_distance;
	float	FOV = (60  * (M_PI / 180));
	good_ray_distance = ray->distance * cos(ray_angle - mlx->player->rotation);
	projection_distance = (mlx->width / 2) / tan(FOV / 2);
	projection_height = (TILE_SIZE / good_ray_distance) * projection_distance;
	draw_wall(mlx->image, // image
	i, // x
	((mlx->height / 2) - (projection_height / 2)), // y
	1, // len fog
	projection_height // len wa9ef
	,mlx
	,hit_x , hit_y,was_hit_vertical, ray_angle);
}
