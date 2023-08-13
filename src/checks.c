/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/08/13 12:05:37 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_file_cub(char *string)
{
	int	len;

	len = ft_strlen(string);
	if (string[len - 1] != 'b' || string[len - 2] != 'u'
		|| string[len - 3] != 'c' || string[len - 4] != '.')
	{
		ft_putstr_fd("misiing `.cub` file, Please check it\n", 2);
		exit(EXIT_FAILURE);
	}
}

// void	ft_check_map(char **str)
// {
// 	int i;
// 	int j = 0;
// 	while(str[j])
// 	{
// 		i = 0;
// 		while (str[i])
// 		{
// 			str[]
// 			i++;
// 		}
// 		j++;
// 	}
// }

// int	ft_check_dl(char **str)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (str[j])
// 	{
// 		i = 0;
// 		while (str[j][i])
// 		{
// 			if (str[j][i] == '1' )
// 			i++;
// 		}
// 	}
// 	return (false);
// }

