/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:57:40 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/10 20:12:25 by mbarberi         ###   ########lyon.fr   */
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
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (nb < 3)
		return (2);
	if (nb % 2 == 0 && nb != 2)
		i++;
	while (!(ft_is_prime(i)))
		i += 2;
	return (i);
}

int main(void)
{
	// printf("%d\n", ft_find_next_prime(2147483629));
	printf("%d\n", ft_find_next_prime(2147483630));
}
