/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:51:43 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/08 20:26:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
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
