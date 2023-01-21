/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:57:33 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 16:03:25 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a = 1;
	int b = 9;
	int *p_a;
	int *p_b;

	p_a = &a;
	p_b = &b;

	printf("a = %d, b = %d\n", a, b);
	ft_swap(p_a, p_b);
	printf("a = %d, b = %d\n", a, b);
}
