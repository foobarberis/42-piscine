/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:38:16 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 11:53:10 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (ft_issign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		x *= 10;
		x += *str - '0';
		str++;
	}
	return (x * sign);
}

int main(void)
{
	char s[] = "-+-+-+234242";
	printf("Result ft_atoi :: %d", ft_atoi(s));
}
