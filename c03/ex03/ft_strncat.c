/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:35:08 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 21:11:25 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*p_d;
	char	*p_s;

	p_d = dest;
	p_s = src;
	while (*p_d)
		p_d++;
	while (nb && *p_s)
	{
		*p_d++ = *p_s++;
		nb--;
	}
	*p_d = '\0';
	return (dest);
}
