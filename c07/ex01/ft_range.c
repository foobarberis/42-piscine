/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:11:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 20:44:58 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*r;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	r = malloc(sizeof(*r) * size);
	while (i < size)
	{
		r[i] = min + i;
		i++;
	}
	return (r);
}
