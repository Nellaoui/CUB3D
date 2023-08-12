/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:44:07 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/12 13:08:04 by ndahib           ###   ########.fr       */
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


/*---------------------noaman----------------------------*/
void	ft_check_file_cub(char *string);
/*-------------------------------------------------------*/

/*----------------------MLX_HOOK-------------------------*/
void	move_on(void *prm);
void	draw_player(void *param);
# endif
