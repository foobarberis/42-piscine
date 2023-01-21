/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:31:49 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 16:35:53 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* open/read/close the map and pass it to valid_map */
int	orc_map(char *map, t_map *st_map)
{
	int		fd;
	int		rd;
	int		cd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	buff = malloc(BUFF_SIZE + 1);
	rd = read(fd, buff, BUFF_SIZE);
	if (rd == -1)
		return (-1);
	buff[rd] = '\0';
	if (valid_map(buff, st_map) == -1)
		return (-1);
	cd = close(fd);
	if (cd == -1)
		return (-1);
	free(buff);
	return (0);
}

/* perform all the tests and return a value to the main */
int	valid_map(char *map, t_map *st_map)
{
	int	lim;

	lim = check_header(map);
	if (!lim)
		return (-1);
	if (!(parse_map_header(map, st_map, lim)))
		return (-1);
	if (st_map->em == st_map->ob || st_map->em == st_map->fu
		|| st_map->ob == st_map->fu)
		return (-1);
	if (!(empty_line(map)))
		return (-1);
	if (!(st_map->li == count_lines(map)) || st_map->li == 0)
		return (-1);
	st_map->ch = count_chars(map);
	if (!(st_map->ch))
		return (-1);
	if (!(check_chars(map, st_map)))
		return (-1);
	st_map->map = build_array(map, st_map);
	st_map->nmap = build_matrix_1(st_map->map, st_map);
	return (1);
}

/* parse the header and extract useful information */
int	parse_map_header(char *map, t_map *st_map, int lim)
{
	int		i;
	char	*p;

	i = 0;
	p = map;
	st_map->li = 0;
	while (ft_isdigit(*p) && i < lim)
	{
		st_map->li = st_map->li * 10 + (*p - '0');
		i++;
		p++;
	}
	if (ft_isprintable(*p))
		st_map->em = *p++;
	if (ft_isprintable(*p))
		st_map->ob = *p++;
	if (ft_isprintable(*p))
		st_map->fu = *p;
	return (1);
}

int	map_error(void)
{
	write(2, "map error\n", 9);
	return (-1);
}
