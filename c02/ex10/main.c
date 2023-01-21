/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:40:34 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/04 17:59:59 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (size != 0 && i < size - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
		++i;
	return (i);
}

int main(void)
{
	char dest[1];
	char src[] = "Hello";

	printf("dest = %s\n", dest);
	printf("src = %s\n\n", src);
	printf("Return : %d\n\n", ft_strlcpy(dest, src, sizeof(dest)));
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
}
