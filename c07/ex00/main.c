/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:51:43 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 20:07:21 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
	int   l;
	char *str;
	char *p_s;

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

int main(void)
{
	char s[] = "Hello World";
	char *p_s = ft_strdup(s);
	printf("%s", p_s);
	free(p_s);
	return 0;
}
