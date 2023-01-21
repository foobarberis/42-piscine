/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:31:41 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 16:29:33 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int			i;
	t_map		st_map;
	t_square	st_square;

	i = 1;
	while (i < argc)
	{
		if (orc_map(argv[i], &st_map) == -1)
		{
			write(2, "map error\n", 9);
			i++;
		}
		else
		{
			solve(&st_map, &st_square);
			i++;
		}
	}
	return (0);
}
