/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:23:24 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 13:26:52 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i])
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
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
