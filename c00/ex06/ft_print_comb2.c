/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:12:59 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 11:29:34 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_n(char n)
{
	int	y;
	int	z;

	if (n > 9)
	{
		y = n / 10;
		z = n % 10;
		ft_putchar(y + '0');
		ft_putchar(z + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(n + '0');
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_n(i);
			ft_putchar(' ');
			ft_print_n(j);
			if (i < 98 || j < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			++j;
		}
		++i;
	}
}
