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
#include <stdio.h>

void	ft_swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

int	ft_attack(int *arr, int n)
{
	int	a[2][n];
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		a[0][i] = i;
		a[1][i] = arr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_abs(a[0][i] - a[0][j]) == ft_abs(a[1][i] - a[1][j]))
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
	int	c;
	int n = 11;
	int	ns;
	int	a[n];

	i = 0;
	ns = 0;
	while (i < n)
	{
		a[i] = i;
		i++;
	}
	while (ft_permute(a, n))
	{
		if (!ft_attack(a, n))
		{
			i = 0;
			ns++;
			while (i < n)
			{
				c = a[i] + '0';
				write(1, &c, 1);
				i++;
			}
			write(1, "\n", 1);
		}
	}
	return (ns);
}

int main(void)
{
	printf("\nNumber of solutions :: %d\n", ft_ten_queens_puzzle());
	return 0;
}
