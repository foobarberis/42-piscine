/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:04:49 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 16:12:46 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void 	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
	int a = 8;
	int b = 2;
	int div = 0;
	int mod = 1;
	int *p_div;
	int *p_mod;

	p_div = &div;
	p_mod = &mod;

	printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
	ft_div_mod(a, b, p_div, p_mod);
	printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
}
