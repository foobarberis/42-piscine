/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:09:28 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/21 20:25:08 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 1;
	while (str[i])
	{
		if (space && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!space && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		space = !((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9'));
		i++;
	}
	return (str);
}
