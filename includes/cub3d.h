/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:44:07 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/15 14:54:43 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500000
# endif

#define	WIDGHT	700
#define	HEIGHT	700

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_cub3d
{
	mlx_t	*mlx;
	mlx_image_t	*image;
	char	*map;
}	t_cub3d;

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
int	ft_check_floor(char **str, int j);
int	ft_check_dl(char *str);
int	ft_check_data(char **str);
int	ft_good(char **map, int j, int i);
char	**ft_split_map(char *string);
char	*ft_map(char *string);
int	ft_st(char *str);
int ft_nd(char *str);
int	ft_rd(char *str);
int	ft_rgb(char **str);
int ft_north(char *str);
int	ft_west(char *str);
int ft_east(char *str);
int ft_south(char *str);
int	ft_map_line(char **str);
int	give_index(char *str);
char **ft_hold_map(char *str);
int st_line(char *map);
int	last_line(char **map);
void	ft_double_player(char **map);
int	ft_player(char	**map);
int	ft_check_valid(char **map);
void	ft_checks(t_cub3d *s, char **av);
void	ft_cub3d(char **av);
/*-------------------------------------------------------*/

/*----------------------MLX_HOOK-------------------------*/
void	move_on(void *prm);
void	draw_player(void *param);
# endif
