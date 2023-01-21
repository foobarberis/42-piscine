/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:15:52 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 16:26:13 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	div = *a / *b;
	mod = *a % *b;

	*a = div;
	*b = mod;
}

int main(void)
{
	int a = 15;
	int b = 7;
	int *p_a;
	int *p_b;

	p_a = &a;
	p_b = &b;

	printf("a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(p_a, p_b);
	printf("a = %d, b = %d\n", a, b);
}
