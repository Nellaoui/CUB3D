/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/31 13:32:44 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cub3d(char **av)
{
	t_cub3d		mlx_lib;

	ft_checks(&mlx_lib, av);
	if (initilize_cub3d(&mlx_lib))
	{
		free(mlx_lib.player);
		exit(1);
	}
	// loading_wall(&mlx_lib);
	draw_c_f(&mlx_lib);
	render_map(&mlx_lib);
	// render_player(&mlx_lib);
	mlx_loop(mlx_lib.mlx);
	mlx_terminate(mlx_lib.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_cub3d(av);
	else
	{
		ft_putstr_fd("Error : Number of arguments isn't Correct\n", 2);
		return (1);
	}
	return (0);
}
