/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:31:54 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 16:39:35 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* check if only chars from the header are used in the map */
int	check_chars(char *map, t_map *st_map)
{
	char	*p;

	p = map;
	while (*p != '\n')
		p++;
	p++;
	while (*p)
	{
		if (!(*p == '\n' || *p == st_map->em || *p == st_map->ob
				|| *p == st_map->fu))
			return (-1);
		p++;
	}
	return (1);
}

/* checks if the map contains empty lines */
int	empty_line(char *map)
{
	char	*p;

	p = map;
	while (*p != '\n')
		p++;
	p++;
	while (*p)
	{
		if (*p == '\n' && *(p + 1) == '\n')
			return (-1);
		p++;
	}
	return (1);
}

/* count the number of lines in the file */
int	count_lines(char *map)
{
	int		l;
	char	*p;

	l = 0;
	p = map;
	while (*p != '\n')
		p++;
	p++;
	while (*p)
	{
		if (*p == '\n')
			l++;
		p++;
	}
	return (l);
}

/* count the number of characters in the file */
int	count_chars(char *map)
{
	int		c;
	int		i;
	char	*p;

	i = 0;
	p = map;
	while (*p != '\n')
		p++;
	p++;
	if (*p == '\n')
		return (-1);
	while (*p++ != '\n')
		i++;
	c = i;
	i = 0;
	while (*p)
	{
		while (*p++ != '\n')
			i++;
		if (i != c)
			return (-1);
		else
			i = 0;
	}
	return (c);
}

/* check if the header is valid and return the position at which number of
 * lines stops */
int	check_header(char *map)
{
	int		i;

	i = 0;
	if (!(ft_isdigit(map[0])))
		return (-1);
	while (map[i] != '\n' && ft_isprintable(map[i]))
		i++;
	i -= 3;
	if (i < 1)
		return (-1);
	return (i);
}
