/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:11:20 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/15 15:11:22 by mbarberi         ###   ########lyon.fr   */
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

int	ft_hasduplicates(char *s, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
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
	char	*p_b;
	int		len;

	p_b = base;
	len = 0;
	if (len == 1 || !*base)
		return (0);
	while (*p_b++)
	{
		if (*p_b == '+' || *p_b == '-' || *p_b == '\t' || *p_b == '\n'
			|| *p_b == '\v' || *p_b == '\f' || *p_b == '\r' || *p_b == ' ')
			return (0);
		len++;
	}
	if (ft_hasduplicates(base, len))
		return (0);
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		l;
	long	n;
	char	num[256];

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
		while (n != 0)
		{
			num[i++] = base[n % l];
			n /= l;
		}
		while (i != 0)
			write(1, &num[--i], 1);
	}
}
