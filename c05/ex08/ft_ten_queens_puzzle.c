/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:32 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/13 19:31:35 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

int	ft_abs(int n, char c, int opt)
{
	if (opt == 1)
	{
		if (n < 0)
			return (n *= -1);
		else
			return (n);
	}
	if (opt == 0)
	{
		write(1, &c, 1);
	}
	return (0);
}

int	ft_attack(int *arr)
{
	int	a[2][10];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		a[0][i] = i;
		a[1][i] = arr[i];
		i++;
	}
	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			if (ft_abs(a[0][i] - a[0][j], '0', 1) ==
				ft_abs(a[1][i] - a[1][j], '0', 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_permute(int *a, int n)
{
	int	k;
	int	l;
	int	lo;
	int	hi;

	k = n - 2;
	while (k >= 0 && a[k] > a[k + 1])
		k--;
	if (k < 0)
		return (0);
	l = n - 1;
	while (a[k] > a[l])
		l--;
	ft_swap(&a[k], &a[l]);
	lo = k + 1;
	hi = n - 1;
	while (lo < hi)
	{
		ft_swap(&a[lo], &a[hi]);
		lo++;
		hi--;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	ns;
	int	a[10];
	int	*p_a;

	i = 0;
	ns = 0;
	p_a = a;
	while (i < 10)
		*p_a++ = i++;
	while (ft_permute(a, 10))
	{
		if (!ft_attack(a))
		{
			i = 0;
			ns++;
			while (i < 10)
			{
				ft_abs(0, a[i] + '0', 0);
				i++;
			}
			write(1, "\n", 1);
		}
	}
	return (ns);
}
