/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:48:05 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/11 12:49:13 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (*s1 == *s2)
	{
		if (!*s1)
			return (0);
		if (++i >= n)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int main(void)
{
	int n = 1;
	char s1[0];
	char s2[0];

	printf("Return value ft_strncmp : %d\n", ft_strncmp(s1, s2, n));
	printf("Return value strncmp : %d\n", strncmp(s1, s2, n));
}
