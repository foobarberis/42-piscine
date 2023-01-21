/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:43:52 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/05 12:44:26 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_first_comb(int *buff, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		buff[i] = i;
		i++;
	}
}

void	ft_print_comb(int *buff, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(buff[i] + '0');
		i++;
	}
}

void	ft_separator(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_combn(int n)
{
	int	s[10];
	int	max;
	int	x;
	int	i;

	i = n;
	if (n <= 0 || n >= 10)
		return ;
	ft_first_comb(s, n);
	while (i > 0)
	{
		max = 10;
		ft_print_comb(s, n);
		while (i--)
		{
			x = s[i];
			if (x < --max)
			{
				while (i < n)
					s[i++] = ++x;
				ft_separator();
				break ;
			}
		}
	}
}
