/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:45:55 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 18:40:40 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	*p_a;
	int	*p_z;
	int	i;

	i = 0;
	while (i != (size / 2))
	{
		p_a = &tab[i];
		p_z = &tab[size - ++i];
		ft_swap(p_a, p_z);
	}
}
