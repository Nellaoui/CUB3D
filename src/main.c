/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/12 13:12:50 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_split_map(char *string)
{
	char **splited;
	splited = ft_split(string, '\n');
	if (!splited)
		return (0);
	return (splited);
}

char	*ft_map(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		exit(EXIT_FAILURE);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
}

void	ft_checks(t_cub3d *s, char **av)
{
	ft_check_file_cub(av[1]);
	s->map = ft_map(av[1]);
	ft_split_map(s->map);
}

void	ft_cub3d(char **av)
{
	t_cub3d mlx_lib;
	(void)av;

	// ft_checks(&mlx_lib, av);
	mlx_lib.mlx = mlx_init(WIDGHT, HEIGHT, "cub3d", true);
	if (!mlx_lib.mlx)
		printf("error\n");
	if (!(mlx_lib.image = mlx_new_image(mlx_lib.mlx, 25, 25)))
		printf("error in creaitin new_image\n");
	mlx_image_to_window(mlx_lib.mlx, mlx_lib.image, 350, 350);
	mlx_loop_hook(mlx_lib.mlx, draw_player, (void *)(mlx_lib.image));
	mlx_loop_hook(mlx_lib.mlx, move_on, &(mlx_lib));
	mlx_loop(mlx_lib.mlx);
	mlx_terminate(mlx_lib.mlx);
}

int main(int ac, char **av)
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
