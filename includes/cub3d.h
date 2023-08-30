/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:44:07 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/30 19:18:53 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500000
# endif

#define	WIDGHT	900
#define	HEIGHT	1000
#define	TILE_SIZE	50
#define	CAST	0.2

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct	s_coordinates
{
	int	x;
	int	y;
}	t_coordinate;

typedef	struct	s_ray
{
	float	ray_angle;
	float	point_wall_x;
	float	point_wall_y;
	float	distance;
	float	next_horzintal_x;
	float	next_horzintal_y;
	float	next_vertical_x;
	float	next_vertical_y;
	float	vertical_founded;
	float	horizantal_founded;
	float	hor_wall_hit_x;
	float	hor_wall_hit_y;
	float	ver_wall_hit_x;
	float	ver_wall_hit_y;
} t_ray;

typedef	struct	s_player
{
	int		x;
	int		y;
	float	radius;
	int		direction;
	double	rotation;
	double	rotate_speed;
	int		move_speed;
	int		move;
	int 		left_right;
	int			compas;

}	t_player;

typedef struct s_cub3d
{
	char		**holdmap;
	uint32_t	tile_y;
	uint32_t	tile_x;
	t_player	*player;
	mlx_image_t	*image;
	int			color;
	mlx_t		*mlx;
	int			rows;
	int			colons;
	long		width;
	long		height;
	int			c_st;
	int			c_nd;
	int			c_rd;
	int			f_st;
	int			f_nd;
	int			f_rd;
	mlx_texture_t	*texture[4];
	int			display_height;
	int			display_width;
}	t_cub3d;

typedef enum e_type
{
	NORTH = 1,
	WEST,
	EAST,
	SOUTH,
} t_type;
// typedef struct s_data
// {
// 	int	st;
// 	int	nd;
// 	int rd;
// } t_data

/*---------------------noaman----------------------------*/
void	ft_check_file_cub(char *string);
int	ft_check_dl(char *str);
int	ft_map_line(char **str);
int	ft_check_floor(char **str, int j, t_cub3d *s);
int	ft_check_dl(char *str);
int	ft_check_data(char **str, t_cub3d *s);
int	ft_good(char **map, int j, int i);
char	**ft_split_map(char *string);
char	*ft_map(char *string);
int	ft_st(char *str);
int ft_nd(char *str);
int	ft_rd(char *str);
int	ft_rgb(char **str, t_cub3d *s);
int ft_north(char *str, t_cub3d *s);
int	ft_west(char *str, t_cub3d *s);
int ft_east(char *str, t_cub3d *s);
int ft_south(char *str, t_cub3d *s);
int	ft_map_line(char **str);
int	give_index(char *str);
char **ft_hold_map(char *str);
int st_line(char *map);
int	last_line(char **map);
void	ft_double_player(char **map);
int	ft_player(char	**map);
int		ft_check_valid(char **map);
void	ft_checks(t_cub3d *s, char **av);
int ft_check_valid_rgb(char **str, int j, int count, t_cub3d *s);
void	ft_cub3d(char **av);
/*---------------------------DRAW----------------------------*/
// void	draw_cercle(mlx_image_t *image, int center_x, int center_y, int radius);
void	draw_ray(mlx_image_t *image, double x1, double y1, double x2, double y2);
void	casting(t_cub3d *mlx , double ray_angle,t_ray *s);
void	casting_vertical(t_cub3d *mlx , double ray_angle,t_ray *s);
double	ft_absolute_angle(double ray_angle);
void	cast_ray(t_cub3d *cub3d);
void	ft_give_direction(t_cub3d *cub3d);

/*---------------------Initilisation---------------------*/
void	initilize_cub3d(t_cub3d *my_struct);
/*----------------------MLX_HOOK-------------------------*/
// void	move_on(void *prm);
void	move_on(mlx_key_data_t key, void *prm);
void	render_map(t_cub3d *s);
void	draw_player(void *param);
void	update_after_move(void *param);
void	render_player(t_cub3d *mlx_lib);

/*-------------------------TOOOLS-------------------------*/
int		number_of_rows(char **map);
int		number_of_colons(char *map);
void	printf_double_pointer(char **map);
uint32_t createcolor(int red, int green, int blue, float alpha);
void	draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2);

/*----------------------------RAYCASTING------------------*/
void	cast_ray(t_cub3d *cub3d);
void    render_wall(t_cub3d *mlx, t_ray *ray, int i, float	ray_angle, float hit_x, float hit_y, int was_hit_vertical);
# endif
