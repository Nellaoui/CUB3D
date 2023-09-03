/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:58:13 by nelallao          #+#    #+#             */
/*   Updated: 2023/09/03 17:57:36 by ndahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
// #include <math.h>
// #include <stdio.h>

// void	f(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = *c + 2;
// }

// int main()
// {
// 	char s[] = "abcd";
// 	ft_striteri(s, f);
// 	printf("%s=", s);
// }
