/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:54:31 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/22 19:34:22 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*a;

	if (length <= 0)
		return (NULL);
	i = 0;
	a = malloc(sizeof(int) * length);
	if (!a)
		return (NULL);
	while (i < length)
	{
		a[i] = f(tab[i]);
		i++;
	}
	return (a);
}
