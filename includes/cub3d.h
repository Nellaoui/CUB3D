/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:44:07 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 16:12:36 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 500000
# endif

#define	WIDGHT	900
#define	HEIGHT	1000
#define	TILE_SIZE	50
#define	SCALE	0.2
// #define	MAXIMIZE	3

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef enum e_type
{
	NORTH = 1,
	WEST,
	EAST,
	SOUTH,
} t_type;

typedef struct s_coordinate
{
	uint32_t	x;
	uint32_t	y;
}	t_coordinate;

typedef struct s_direction
{
	int	right;
	int	down;
	int	left;
	int	up;
}	t_direction;

typedef struct s_union
{
	t_coordinate	inter;
	t_coordinate	step;
	t_coordinate	hit;
	t_coordinate	distance;
	float			ray_angle;
	int				was_hit_vertical;
}	t_union;

typedef struct s_ray
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
	float	hit_x;
	float	hit_y;
	float	was_hit_vertical;
	float	ver_wall_hit_y;
	float	horizantal_distance;
	float	vertical_distance;
	// float	hit_x;
	// float	hit_y;
} t_ray;

typedef	struct	s_player
{

}
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
	int 	left_right;
	int		compas;

}	t_player;

typedef struct s_cub3d
{
	char		**holdmap;
	t_player	*player;
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			rows;
	float	hit_x;
	float	hit_y;
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
	int32_t			display_height;
	int32_t			display_width;
	float				scale_width;
	float				scale_height;
}	t_cub3d;

/*---------------------noaman----------------------------*/
void		ft_check_file_cub(char *string);
int			ft_check_dl(char *str);
int			ft_map_line(char **str);
int			ft_check_floor(char **str, int j, t_cub3d *s);
int			ft_check_dl(char *str);
int			ft_check_data(char **str, t_cub3d *s);
int			ft_good(char **map, int j, int i);
char		**ft_split_map(char *string);
char		*ft_map(char *string);
int			ft_st(char *str);
int			ft_nd(char *str);
int			ft_rd(char *str);
int			ft_rgb(char **str, t_cub3d *s);
int			ft_north(char *str, t_cub3d *s);
int			ft_west(char *str, t_cub3d *s);
int			ft_east(char *str, t_cub3d *s);
int			ft_south(char *str, t_cub3d *s);
int			ft_map_line(char **str);
int			give_index(char *str);
char		**ft_hold_map(char *str);
int			st_line(char *map);
int			last_line(char **map);
void		ft_double_player(char **map);
int			ft_player(char	**map);
int			ft_check_valid(char **map);
void		ft_checks(t_cub3d *s, char **av);
int			ft_check_valid_rgb(char **str, int j, int count, t_cub3d *s);
void		ft_cub3d(char **av);
int			ft_chek_invalid(char **str);
int	ft_wall_here(float x, float y, t_cub3d *mlx);
void	casting(t_cub3d *mlx , double ray_angle	,t_ray *s);
/*---------------------------DRAW----------------------------*/
void		draw_c_f(t_cub3d *mlx);
void		render_map(t_cub3d *s);
void		draw_player(void *param);
void		cast_ray(t_cub3d *cub3d);
void		update_after_move(void *param);
void		render_player(t_cub3d *mlx_lib);
void		casting_horizontal(t_cub3d *mlx, double ray_angle, t_ray *s);
void		render_wall(t_cub3d *mlx, t_ray *ray, int i, float ray_angle);
// void	draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2);
// void		draw_cercle(mlx_image_t *image, int center_x, int center_y, int radius);
// void	draw_ray(mlx_image_t *image, double x1, double y1, double x2, double y2);
void		casting_vertical(t_cub3d *mlx, double ray_angle, t_ray *s);

/*---------------------Initilisation---------------------*/
int		initilize_cub3d(t_cub3d *my_struct);
/*----------------------MLX_HOOK-------------------------*/
// void	move_on(void *prm);
void		move_on(mlx_key_data_t key, void *prm);

/*-------------------------TOOOLS-------------------------*/
int			colons(char **map);
int			number_of_rows(char **map);
int			number_of_colons(char *map);
void		printf_double_pointer(char **map);
double		ft_absolute_angle(double ray_angle);
void		free_double_pointer(char **file);
uint32_t	createcolor(int red, int green, int blue, float alpha);
/*-----------------------------------KEYS------------------------*/
void	release_keys(mlx_key_data_t *key, t_cub3d	*mlx);
void	mouvement_keys(mlx_key_data_t *key, t_cub3d	*mlx);
# endif
