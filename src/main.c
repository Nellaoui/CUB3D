/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:52:51 by ndahib            #+#    #+#             */
/*   Updated: 2023/08/16 08:39:05 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	give_index(char *str)
{
	int j;

	j = 0;
	while(str[j])
	{
		if (str[j] == '1' && str[j+1] == '1' && str[j+2] == '1')
		{
			while(str[j])
			{
				if (str[j] == '\n' || j == 0)
					return (j);
				j--;
			}
		}
		j++;
	}
	return (0);
}

int	last_line(char **map)
{
	int i;
	int j;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		j++;
	}
	return (j - 1);
}


void	ft_checks(t_cub3d *s, char **av)
{
	char **file;
	char **holdmap;

	ft_check_file_cub(av[1]);
	s->map = ft_map(av[1]);
	if (ft_check_dl(s->map))
	{
		ft_putstr_fd("somthing went wrong : Double line in the map", 2);
			exit(EXIT_FAILURE);
	}
	file = ft_split_map(s->map);
	holdmap = ft_hold_map(s->map);
	if (ft_check_valid(holdmap))
		exit(1);
	if (ft_check_data(file))
		puts("GOOOOOOOD");
	else
		puts("NOOOOOOT GOOOOOOOD");

}

void	ft_cub3d(char **av)
{
	t_cub3d mlx_lib;
	(void)av;

	ft_checks(&mlx_lib, av);
	mlx_lib.mlx = mlx_init(WIDGHT, HEIGHT, "cub3d", true);
	if (!mlx_lib.mlx)
		ft_putstr_fd("error\n", 2);
	if (!(mlx_lib.image = mlx_new_image(mlx_lib.mlx, 25, 25)))
		ft_putstr_fd("error in creaitin new_image\n", 2);
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

