/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:32:00 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 18:47:12 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* turns the 1d array into a 2d array */
char	**build_array(char *buff, t_map *st_map)
{
	int		i;
	int		j;
	char	**a;

	i = 0;
	j = 0;
	a = malloc(st_map->li * sizeof(char *));
	while (i < st_map->li)
		a[i++] = malloc(st_map->ch * sizeof(char));
	while (*buff != '\n')
		buff++;
	buff++;
	i = 0;
	while (j < st_map->li)
	{
		while (*buff != '\n')
			a[j][i++] = *buff++;
		buff++;
		j++;
		i = 0;
	}
	return (a);
}

/* turns the char ** into a int **, replacing obstacles
** with 1 and empty squares with 0
*/
int	**build_matrix_1(char **buff, t_map *st_map)
{
	int		i;
	int		j;
	int		**a;

	i = 0;
	j = 0;
	a = malloc(st_map->li * sizeof(int *));
	while (i < st_map->li)
		a[i++] = malloc(st_map->ch * sizeof(int));
	i = 0;
	while (j < st_map->li)
	{
		while (i < st_map->ch)
		{
			if (buff[j][i] == st_map->em)
				a[j][i] = 0;
			else
				a[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (build_matrix_2(a, st_map));
}

/* counts the number of obstacles from the top left corner */
int	**build_matrix_2(int **matrix, t_map *st_map)
{
	int		i;
	int		j;
	int		v;

	i = 0;
	j = 0;
	v = 0;
	while (j < st_map->li)
	{
		while (i < st_map->ch)
		{
			if ((matrix[j][i]) >= 1)
			{
				if (j + 1 != st_map->li)
					matrix[j + 1][i] += 1;
				v++;
			}
			matrix[j][i] = v;
			i++;
		}
		i = 0;
		v = 0;
		j++;
	}
	return (matrix);
}
