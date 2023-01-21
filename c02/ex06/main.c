/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:48:54 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/04 15:54:31 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] >= ' ' && str[i] <= '~'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	char s[] = "asdf\x07";

	printf("Return value : %d", ft_str_is_printable(s));
}
