/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:09:28 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/07 14:21:13 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lower(int n)
{
	if (n >= 'a' && n <= 'z')
		return (1);
	else
		return (0);
}

int	ft_is_separator(int n)
{
	if (n >= ' ' && n <= '0')
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (ft_is_lower(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if ((ft_is_lower(str[i])) && (ft_is_separator(str[i - 1])))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
