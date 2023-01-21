/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:45:55 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/05 11:06:02 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int *p_a;
	int *p_z;
	int i;

	i = 0;
	while (i != (size / 2))
	{
		p_a = &tab[i];
		p_z = &tab[size - ++i];
		ft_swap(p_a, p_z);
	}
}

int	main(void)
{
	 int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	// int arr[] = {0, 1, 2};
	int size = 16;
	int *p_arr;
	int i = 0;

	p_arr = &arr[0];
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}

	printf("\n");
	ft_rev_int_tab(p_arr, size);

	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}
