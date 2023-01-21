/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:08:27 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/10 14:01:46 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*h;
	char	*n;

	if (!*to_find)
		return (char *)(str);
	if (!*str)
		return (0);
	while (*str)
	{
		h = str;
		n = to_find;
		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (char *)(str);
		str++;
	}
	return (0);
}

int main(void)
{
	char *haystack = "lskjfl";
	char *needle = "lskjfls";
	char *ft_result = ft_strstr(haystack, needle);
	char *result = strstr(haystack, needle);

	printf("copy :: haystack: %s\n needle: %s\n found: %s\n\n", haystack, needle, ft_result);
	printf("original :: haystack: %s\n needle: %s\n found: %s\n", haystack, needle, result);
	return 0;
}
