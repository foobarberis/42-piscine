/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:23:33 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 11:29:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	char *p_dest;

	i = 0;
	p_dest = dest;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			return (p_dest);
		i++;
	}
}

int main(void)
{
	char dest[15];
	char src[] = "This is a test";

	printf("dest = %s\n", dest);
	printf("src = %s\n\n", src);
	ft_strcpy(dest, src);
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
}
