/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:23:24 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 11:48:32 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	  *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned long	i;
	char 			*p_dest;

	i = 0;
	p_dest = dest;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (p_dest);
}

int main(void)
{
	char dest[30];
	char src[] = "Hello";

	printf("dest = %s\n", dest);
	printf("src = %s\n\n", src);
	ft_strncpy(dest, src, 10);
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
}
