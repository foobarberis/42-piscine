/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:04:15 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/22 14:24:13 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return ((unsigned int)(p - s));
}

void	ft_abs(long *n)
{
	*n *= -1;
	write(1, "-", 1);
}

int	ft_hasduplicates(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_base(char *base)
{
	char	*p;

	p = base;
	if (!base[0] || !base[1])
		return (0);
	if (ft_hasduplicates(base))
		return (0);
	while (*p)
	{
		if (*p == '+' || *p == '-')
			return (0);
		p++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		l;
	long	n;
	char	num[128];

	i = 0;
	n = nbr;
	l = ft_strlen(base);
	if (ft_valid_base(base))
	{
		if (n == 0)
		{
			write(1, &base[0], 1);
			return ;
		}
		if (n < 0)
			ft_abs(&n);
		while (n)
		{
			num[i++] = base[n % l];
			n /= l;
		}
		while (--i >= 0)
			write(1, &num[i], 1);
	}
}
