/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:40:34 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 14:26:33 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

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
