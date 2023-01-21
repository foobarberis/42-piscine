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

#include <stdio.h>
#include <stdlib.h>

#define MIN -2147483
#define MAX 2147483

// #define MIN -10
// #define MAX 10
int *ft_range(int min, int max)
{
	int i;
	int size;
	int *r;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	r = malloc(sizeof(*r) * size);
	while (i < size)
	{
		r[i] = min + i;
		i++;
	}
	return (r);
}

int main(void)
{
	size_t i = 0;
	int *t = ft_range(MIN, MAX);
	while (i < MAX - MIN)
	{
		printf("%d, ", t[i]);
		i++;
	}
	free(t);
}
