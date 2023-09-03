/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:17:52 by nelallao          #+#    #+#             */
/*   Updated: 2023/09/03 21:14:19 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* "sizeof" operator gives the size of the array in bytes */
/* calloc: allocate n objects of size size */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}
