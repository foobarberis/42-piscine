/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:41:23 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 19:21:34 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*p_a;
	int	*p_z;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		p_a = &tab[i];
		p_z = &tab[i + 1];
		if (*p_a > *p_z)
		{
			ft_swap(p_a, p_z);
			i = 0;
		}
		i++;
	}
	if (tab[0] > tab[1])
		ft_sort_int_tab(tab, size);
}
