/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:35:02 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/21 20:49:16 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (0);
	dest[i] = 0;
	while (i-- > 0)
		dest[i] = src[i];
	return (dest);
}

char	**ft_create_tab(char *buffer, int size, int i, int count)
{
	char	last;
	char	**tab;

	last = 0;
	while (i < size)
	{
		if (buffer[i] && !last)
			count++;
		last = buffer[i++];
	}
	i = 0;
	last = 0;
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		if (*buffer && !last)
			tab[i++] = ft_strdup(buffer);
		last = *buffer;
		buffer++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	char	*buffer;
	int		i;
	int		j;

	len = 0;
	while (str[len])
		len++;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		buffer[i] = str[i];
		while (charset[j])
			if (str[i] == charset[j++])
				buffer[i] = '\0';
		i++;
	}
	buffer[i] = '\0';
	return (ft_create_tab(buffer, len, 0, 0));
}
