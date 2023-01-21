/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:57:36 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/18 22:55:04 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/* adds a new link into the linked list representing the dictionary */
t_dict	*add_link_dict(t_dict *list, size_t key, char *name)
{
	t_dict	*tmp;

	tmp = malloc(sizeof(t_dict));
	if (tmp)
	{
		tmp->key = key;
		tmp->name = ft_strdup(name);
		tmp->next = list;
	}
	return (tmp);
}

/* handle file manipulation and calls gen_dict() */
t_dict	*orc_dict(t_dict *list, char *dict)
{
	int		fd;
	int		rd;
	int		cd;
	char	*p_buff;
	char	buff[BUFF_SIZE + 1];

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (NULL);
	rd = read(fd, buff, BUFF_SIZE);
	if (rd == -1)
		return (NULL);
	buff[rd] = '\0';
	p_buff = buff;
	list = gen_dict(p_buff, list);
	cd = close(fd);
	if (cd == -1)
		return (NULL);
	return (list);
}

/* extract key and name on each line and produces a linked list */
t_dict	*gen_dict(char *buff, t_dict *list)
{
	size_t	x;
	char	*name;

	while (*buff)
	{
		x = 0;
		while (ft_isdigit(*buff))
		{
			x = x * 10 + (*buff - '0');
			buff++;
		}
		while (*buff == ' ' || *buff == ':')
			buff++;
		name = get_name(buff);
		list = add_link_dict(list, x, name);
		if (x == MAX_SIZE)
			return (list);
		buff++;
	}
	free(name);
	return (list);
}

/* extract the names from the file */
char	*get_name(char *buff)
{
	int		i;
	char	*name;

	i = 0;
	name = malloc(sizeof(char) * 256);
	while (ft_isprintable(*buff) || *buff != '\n')
	{
		if (ft_isspace(*buff))
		{
			while (!(ft_isprintable(*buff)))
				buff++;
			name[i++] = ' ';
		}
		name[i++] = *buff++;
	}
	while (!(ft_isprintable(*buff)))
		buff++;
	name[i] = '\0';
	return (name);
}

/* search for the key in the dictionary and print the name */
int	search_entry(t_dict *dict, size_t n)
{
	while (dict->key != n)
		dict = dict->next;
	ft_putstr(dict->name);
	ft_putstr(" ");
	return (1);
}
