/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:29:06 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/03 16:34:47 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		ft_putchar(str[i]);
		i++;
	}
}

int		main(void)
{
	char s[] = "Hello World!";
	char *p_s;

	p_s = &s[0];
	ft_putstr(p_s);
}
