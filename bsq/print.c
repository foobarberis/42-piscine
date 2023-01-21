/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:32:05 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 18:50:09 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (nb < 0)
		ft_putchar('-');
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	print_array(char **array, int row, int col)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < row)
	{
		while (j < col)
		{
			ft_putchar(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	print_matrix(int **matrix, int row, int col)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < row)
	{
		while (j < col)
		{
			ft_putnbr(matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
