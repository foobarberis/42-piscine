/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:49:31 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:45 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_hasduplicates(char *s, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_base(char *base)
{
	char	*p_b;
	int		len;

	p_b = base;
	len = 0;
	if (len == 1 || !*base)
		return (0);
	while (*p_b++)
	{
		if (*p_b == '+' || *p_b == '-' || *p_b == '\t' || *p_b == '\n'
			|| *p_b == '\v' || *p_b == '\f' || *p_b == '\r' || *p_b == ' ')
			return (0);
		len++;
	}
	if (ft_hasduplicates(base, len))
		return (0);
	return (len);
}

int	ft_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isspaceorsign(int c, int *sign, int check)
{
	if (check == 1)
	{
		if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
			return (1);
		else
			return (0);
	}
	else if (check == 0)
	{
		if (c == '-' || c == '+')
		{
			if (c == '-')
				*sign *= -1;
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	x;
	int	sign;
	int	base_len;
	int	base_index;

	x = 0;
	sign = 1;
	base_len = ft_valid_base(base);
	base_index = 0;
	if (base_len == 0)
		return (0);
	while (ft_isspaceorsign(*str, &sign, 1))
		str++;
	while (ft_isspaceorsign(*str, &sign, 0))
		str++;
	while (1)
	{
		base_index = ft_in_base(*str, base);
		if (base_index == -1)
			break ;
		x = x * base_len + base_index;
		str++;
	}
	return (x * sign);
}
