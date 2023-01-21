/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@32.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:39:56 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 21:58:08 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve(t_map *st_map, t_square *st_square)
{
	int	x;
	int	y;
	int	best;

	x = 0;
	y = 0;
	best = 0;
	while (y < st_map->li)
	{
		while (x < st_map->ch)
		{
			if (possible(st_map, x, y, best + 1))
			{
				st_square->x_s = x;
				st_square->y_s = y;
				best++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	st_square->size = best;
	draw_square(st_map, st_square);
}

int	possible(t_map *st_map, int x_s, int y_s, int best)
{
	int	x_e;
	int	y_e;
	int	res;

	x_e = x_s + best;
	y_e = y_s + best;
	if ((x_e >= st_map->ch) || (y_e >= st_map->li))
		return (0);
	res = st_map->nmap[y_e][x_e] - st_map->nmap[y_e][x_s]
		- st_map->nmap[y_s][x_e] + st_map->nmap[y_s][x_s];
	if (res == 0)
		return (1);
	else
		return (0);
}

void	draw_square(t_map *st_map, t_square *st_square)
{
	int	x_s;
	int	y_s;
	int	x_e;
	int	y_e;

	x_s = st_square->x_s;
	y_s = st_square->y_s;
	x_e = x_s + st_square->size;
	y_e = y_s + st_square->size;
	while (y_s < y_e)
	{
		while (x_s < x_e)
		{
			st_map->map[y_s][x_s] = st_map->fu;
			x_s++;
		}
		x_s = st_square->x_s;
		y_s++;
	}
	print_array(st_map->map, st_map->li, st_map->ch);
}
