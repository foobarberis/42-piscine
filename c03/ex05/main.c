/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:25:06 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/11 12:41:02 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (size < i)
		j += size;
	else
		j += i;
	while (*src && i < (size - 1) && size != 0)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (j);
}

int main(void)
{
	char s1[2] = "";
	char s2[] = "abc";
	char s3[2] = "";
	char s4[] = "abc";

	printf("ft_strcat :: %s :: %u :: sizeof %lu\n", s1, ft_strlcat(s1, s2, sizeof(s1)), sizeof(s1));
	printf("strlcat :: %s :: %lu :: sizeof %lu\n", s3, strlcat(s3, s4, sizeof(s3)), sizeof(s3));
}
