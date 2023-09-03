/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:44:07 by ndahib            #+#    #+#             */
/*   Updated: 2023/09/03 10:29:39 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif

# define WIDGHT 960
# define HEIGHT 540
# define TILE_SIZE 50
# define SCALE 0.2
// #define	MAXIMIZE	3

# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_type
{
	NORTH = 1,
	WEST,
	EAST,
	SOUTH,
}					t_type;

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
	float			ray_angle;
	float			point_wall_x;
	float			point_wall_y;
	float			distance;
	float			next_horzintal_x;
	float			next_horzintal_y;
	float			nx_vert_x;
	float			next_vertical_y;
	float			vertical_founded;
	float			horizantal_founded;
	float			hor_wall_hit_x;
	float			hor_wall_hit_y;
	float			ver_wall_hit_x;
	float			hit_x;
	float			hit_y;
	float			was_hit_vertical;
	float			ver_wall_hit_y;
	float			horizantal_distance;
	float			vertical_distance;
	float			s_start;
	float			projection_height;
	float			y_start;
}					t_ray;

typedef struct s_casting
{
	float			x_inter;
	float			y_inter;
	float			x_step;
	float			y_step;
	int				right;
	int				down;
	int				left;
	int				up;
	float			ver_x_inter;
	float			ver_y_inter;
	float			ver_x_step;
	float			ver_y_step;
	float			ver_right;
	float			ver_down;
	float			ver_left;
	float			ver_up;
}					t_casting;

typedef struct s_p
{
	int				x;
	int				y;
	float			radius;
	int				direction;
	double			rotation;
	double			rotate_speed;
	float			move_speed;
	float			move;
	int				left_right;
	int				compas;

}					t_p;

typedef struct s_cub3d
{
	char			**holdmap;
	t_p				*p;
	mlx_image_t		*image;
	mlx_t			*mlx;
	int				rows;
	float			hit_x;
	float			hit_y;
	int				colons;
	long			width;
	long			height;
	int				c_st;
	int				c_nd;
	int				c_rd;
	int				f_st;
	int				f_nd;
	int				f_rd;
	mlx_texture_t	*texture[4];
	int32_t			display_height;
	int32_t			display_width;
	float			scale_width;
	float			scale_height;
	int				map_press;
	int				map_size;
}					t_cub3d;

/*---------------------noaman----------------------------*/
void				ft_check_file_cub(char *string);
int					ft_check_dl(char *str);
int					ft_map_line(char **str);
int					ft_check_floor(char **str, int j, t_cub3d *s);
int					ft_check_dl(char *str);
int					ft_check_data(char **str, t_cub3d *s);
int					ft_good(char **map, int j, int i);
char				**ft_split_map(char *string);
char				*ft_map(char *string);
int					ft_st(char *str);
void				ft_give_path(char *str, t_cub3d *s);
void				casting_horizontal(t_cub3d *mlx, double ray_angle,
						t_ray *s);
void				casting_vertical(t_cub3d *mlx, double ray_angle, t_ray *s);
void				ft_initialize_cast(t_casting *c, t_ray *s);
void				ft_hor_inter(t_casting *c, float angle, t_cub3d *mlx,
						t_ray *s);
void				ft_ver_inter(float ray_angle, t_cub3d *mlx, t_casting *c);
int					ft_nd(char *str);
int					ft_rd(char *str);
int					ft_rgb(char **str, t_cub3d *s);
int					ft_north(char *str, t_cub3d *s);
int					ft_west(char *str, t_cub3d *s);
int					ft_east(char *str, t_cub3d *s);
int					ft_south(char *str, t_cub3d *s);
int					give_index(char *str);
char				**ft_hold_map(char *str);
int					st_line(char *map);
int					last_line(char **map);
void				ft_double_p(char **map);
int					ft_p(char **map);
int					ft_check_valid(char **map);
void				ft_checks(t_cub3d *s, char **av);
int					ft_check_valid_rgb(char **str, int j, int count,
						t_cub3d *s);
void				ft_cub3d(char **av);
int					ft_chek_invalid(char **str);
int					ft_wall_here(float x, float y, t_cub3d *mlx);
int					ft_wall_here_a(float x, float y, t_cub3d *mlx);
void				casting_horizontal(t_cub3d *mlx, double ray_angle,
						t_ray *s);
void				ft_give_color(char **str, t_cub3d *s, int f_c, int j);
void				ft_norm(t_cub3d *mlx);
void					ft_hardcode(char **str);


/*---------------------------DRAW----------------------------*/
// void				draw_c_f(t_cub3d *mlx);
void				draw_c(t_cub3d *s);
void				draw_f(t_cub3d *s);
void				render_map(t_cub3d *s);
void				draw_p(void *param);
void				cast_ray(t_cub3d *cub3d);
void				update_after_move(void *param);
void				render_p(t_cub3d *mlx_lib);
void				casting_horizontal(t_cub3d *mlx, double ray_angle,
						t_ray *s);
void				render_wall(t_cub3d *mlx, t_ray *ray, int i,
						float ray_angle);
void				casting_vertical(t_cub3d *mlx, double ray_angle, t_ray *s);

/*---------------------Initilisation---------------------*/
int					initilize_cub3d(t_cub3d *my_struct);
/*----------------------MLX_HOOK-------------------------*/
void				move_on(mlx_key_data_t key, void *prm);

/*-------------------------TOOOLS-------------------------*/
int					colons(char **map);
int					number_of_rows(char **map);
int					number_of_colons(char *map);
double				ft_absolute_angle(double ray_angle);
void				free_double_pointer(char **file);
uint32_t			createcolor(int red, int green, int blue, float alpha);
/*-----------------------------------KEYS------------------------*/
// void	release_keys(mlx_key_data_t *key, t_cub3d	*mlx);
// void	mouvement_keys(mlx_key_data_t *key, t_cub3d	*mlx);
#endif
