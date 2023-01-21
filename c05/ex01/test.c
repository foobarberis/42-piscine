/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:46 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 16:25:48 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
	int	r;

	r = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (nb > 1)
	{
		r *= ft_recursive_factorial(nb - 1);
		nb--;
	}
	return (r);
}

int main(void)
{
printf("%d\n", ft_recursive_factorial(5));
}
