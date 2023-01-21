/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:29:29 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/14 18:29:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return ((unsigned int) (p - s));
}

char *ft_strdup(char *src)
{
	int		l;
	char	*str;
	char	*p_s;

	l = 0;
	while (src[l])
		l++;
	str = malloc(l + 1);
	p_s = str;
	while (*src)
		*p_s++ = *src++;
	*p_s = '\0';
	return (str);
}

void ft_putstr(char *str)
{
	char *p_s;

	p_s = str;
	while(*p_s)
		write(1, p_s++, 1);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (nb < 0)
		ft_putchar('-');
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*structures;
	int 				i;

	i = 0;
	structures = malloc(sizeof(struct s_stock_str) * (ac + 1));

	while (i < ac)
	{
		structures[i].size = ft_strlen(av[i]);
		structures[i].str = av[i];
		structures[i].copy = ft_strdup(av[i]);
		i++;
	}
	structures[i].str = 0;
	return (structures);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}
