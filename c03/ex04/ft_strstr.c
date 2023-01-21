/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:08:27 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/10 14:02:58 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*h;
	char	*n;

	if (!*to_find)
		return ((char *)(str));
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
			return ((char *)(str));
		str++;
	}
	return (0);
}
