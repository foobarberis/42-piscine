/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:46:27 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/05 13:02:54 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_first_comb(int *buff, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		buff[i] = i;
		i++;
	}
}

void	ft_print_comb(int *buff, int n)
{
	int i;

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

int	main(void)
{
	ft_print_combn(0);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(1);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(2);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(3);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(4);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(5);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(6);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(7);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(8);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(9);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(10);
	ft_putchar('\n');
	ft_putchar('\n');
}
