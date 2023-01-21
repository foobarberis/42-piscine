/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:47:17 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 18:04:09 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_is_prime(int nb)
{
	int i;
	int h;

	if (nb == 2 || nb == 3)
		return (1);

	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);

	i = 5;
	h = nb / 2;
	while (i <= h)
	{
		if ((nb % i) == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
		// printf("i :: %d\n", i);
	}
	return (1);
}

int main(void)
{
	// int i = 2147483647;
	int i = 0;
	while (i < 1000000)
	{
		if (ft_is_prime(i))
			printf("%d, ", i);
		i++;
	}
}