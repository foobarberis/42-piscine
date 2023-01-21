/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:07:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/11 20:07:15 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return ((unsigned int)(p - s));
}

int	ft_strslen(int size, char **strs)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
		l += ft_strlen(strs[i++]);
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		p;
	int		l;
	char	*str;

	i = 0;
	p = 0;
	l = ft_strslen(size, strs);
	str = malloc(ft_strlen(sep) * size + l + 1);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[p++] = strs[i][j++];
		if (++i == size)
			break ;
		j = 0;
		while (sep[j])
			str[p++] = sep[j++];
	}
	str[p] = 0;
	return (str);
}
