/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:06:54 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/11 20:06:56 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MIN -10
#define MAX 10

int ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

int main(void)
{
	int *tab = NULL;
	int  num = ft_ultimate_range(&tab, 5, 10);
	printf ("num :: %d\n", num);
	for (int i = 0; i < num; ++i)
	{
		printf("Integer case %d: %d\n", i, tab[i]);
	}
	return (0);
}
