/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:15:27 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/18 20:15:29 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *str)
{
	char	*p_s;

	p_s = str;
	while (*p_s)
		write(1, p_s++, 1);
}

size_t	ft_atoi(char *str)
{
	size_t	x;

	x = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_issign(*str))
	{
		if (*str == '-')
			return (ERROR);
		str++;
	}
	while (ft_isdigit(*str))
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	return (x);
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

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}
