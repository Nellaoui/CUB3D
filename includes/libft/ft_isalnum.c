/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:35:08 by nelallao          #+#    #+#             */
/*   Updated: 2022/10/02 19:44:23 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if ((n >= '0' && n <= '9') || (n >= 'a' && n <= 'z') || (n >= 'A'
			&& n <= 'Z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
    printf("%d", ft_isalnum('5'));
}
*/