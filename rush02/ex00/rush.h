/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:15:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/18 20:15:15 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4096
/* when atoi() returns -1, value gets converted to MAX_SIZE */
# define ERROR (18446744073709551615UL)
# define MAX_SIZE 1000000000000000000

typedef struct s_num	t_num;
typedef struct s_dict	t_dict;

struct s_num
{
	int		pos;
	size_t	digit;
	size_t	rank;
	t_num	*next;
};

struct s_dict
{
	char	*name;
	size_t	key;
	t_dict	*next;
};

/* num.c */
t_num	*ft_ntol(t_num	*list, size_t n);
void	process_num(t_num *n_list, t_dict *d_list);
t_num	*add_link_num(t_num *list, size_t d, size_t r, int pos);
void	sub_process_num(t_num *n_list, t_dict *d_list, t_dict *head, int *teen);
/* dict.c */
int		search_entry(t_dict *haystack, size_t needle);
t_dict	*gen_dict(char *buff, t_dict *list);
t_dict	*orc_dict(t_dict *list, char *dict);
t_dict	*add_link_dict(t_dict *list, size_t n, char *name);
char	*get_name(char *buff);
/* utils.c */
size_t	ft_atoi(char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
int		error(void);
int		dict_error(void);
/* char.c */
int		ft_issign(char c);
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_isprintable(char c);
#endif
