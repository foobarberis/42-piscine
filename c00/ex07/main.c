/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:16:04 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/06 11:18:42 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_decomp(int n)
{
	int i;
	int sign;
	char num[15];

	i = 0;
	sign = n;
	if (sign < 0)
		n = -n;
	while (n > 0)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign < 0)
		num[i++] = '-';
	while (i-- != 0)
		ft_putchar(num[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else
		ft_decomp(nb);
}

int main(void)
{
	int i;

	i = -10000;
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(-214658945);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	/*
	   while (i++ <= 10000)
	   {
	   ft_putnbr(i);
	   ft_putchar(',');
	   ft_putchar(' ');
	   }
	   */
}
