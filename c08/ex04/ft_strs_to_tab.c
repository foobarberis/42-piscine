/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:29:29 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/14 18:29:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

unsigned int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return ((unsigned int)(p - s));
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*str;
	char	*p_s;

	l = 0;
	while (src[l])
		l++;
	str = malloc(l + 1);
	p_s = str;
	while (*src)
		*p_s++ = *src++;
	*p_s = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*structures;
	int					i;

	i = 0;
	structures = malloc(sizeof(struct s_stock_str) * (ac + 1));
	while (i < ac)
	{
		structures[i].size = ft_strlen(av[i]);
		structures[i].str = av[i];
		structures[i].copy = ft_strdup(av[i]);
		i++;
	}
	structures[i].str = 0;
	return (structures);
}
