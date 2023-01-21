/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:35:08 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 21:10:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char *s)
{
	char *p;

	p = s;
	while(*p)
		p++;
	return (unsigned int)(p - s);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *p_d;
	char *p_s;

	p_d = dest;
	p_s = src;
	while (*p_d)
		p_d++;
	while (nb && *p_s)
	{
		*p_d++ = *p_s++;
		nb--;
	}
	*p_d = '\0';
	return (dest);
}

int main(void)
{
	char s1[20] = "";
	char s2[] = "World!";
	int n;

	n = 50;
	printf("%s\n", s1);
//	ft_strncat(s1, s2, n);
	strncat(s1, s2, n);
	printf("%s\n", s1);
}
