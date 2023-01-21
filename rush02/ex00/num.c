/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:15:52 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/18 20:15:53 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/* adds a new link into the linked list representing the number */
t_num	*add_link_num(t_num *list, size_t digit, size_t rank, int pos)
{
	t_num	*tmp;

	tmp = malloc(sizeof(t_num));
	if (tmp)
	{
		tmp->digit = digit;
		tmp->rank = rank;
		tmp->pos = pos % 3;
		tmp->next = list;
	}
	return (tmp);
}

/* converts integer n into a linked list */
t_num	*ft_ntol(t_num *list, size_t n)
{
	int		pos;
	size_t	nb;
	size_t	rank;

	nb = n;
	pos = 1;
	rank = 1;
	list = add_link_num(list, 0, 0, -1);
	if (nb == 0)
	{
		list = add_link_num(list, 0, 1, 1);
		return (list);
	}
	while (nb != 0)
	{
		list = add_link_num(list, nb % 10, rank, pos);
		pos++;
		nb /= 10;
		rank *= 10;
	}
	return (list);
}

/* sets a pointer at the start of the list and calls sub_process_num */
void	process_num(t_num *s_nl, t_dict *s_dl)
{
	int		t;
	t_dict	*head;

	t = 0;
	head = s_dl;
	sub_process_num(s_nl, s_dl, head, &t);
}

/* handles the interpretation of the data to print the correct name */
void	sub_process_num(t_num *s_nl, t_dict *s_dl, t_dict *head, int *t)
{
	while (s_nl->pos != -1)
	{
		if ((s_nl->pos == 0) || (s_nl->pos == 1 && *t == 0))
			search_entry(s_dl, s_nl->digit);
		else if (s_nl->digit == 0 && s_nl->pos != 1 && s_nl->next->pos != -1)
			s_nl = s_nl->next;
		s_dl = head;
		*t = 0;
		if (s_nl->pos == 0 && s_nl->digit != 0)
			search_entry(s_dl, 100);
		if (s_nl->pos == 2)
		{
			if (s_nl->digit > 1)
				search_entry(s_dl, s_nl->digit * 10);
			else
				*t = search_entry(s_dl, s_nl->digit * 10 + s_nl->next->digit);
		}
		s_dl = head;
		if ((s_nl->pos == 1 && s_nl->next->pos == 0 && s_nl->next != NULL))
			search_entry(s_dl, s_nl->rank);
		s_dl = head;
		s_nl = s_nl->next;
	}
}
