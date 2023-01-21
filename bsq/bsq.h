/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:31:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/20 16:45:42 by momaiouf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 8192

typedef struct s_map
{
	int		li;
	int		ch;
	char	em;
	char	ob;
	char	fu;
	char	**map;
	int		**nmap;
}	t_map;

typedef struct s_square
{
	int		x_s;
	int		y_s;
	int		size;
}	t_square;

/* solve.c */
void	solve(t_map *st_map, t_square *st_square);
int		possible(t_map *st_map, int x_s, int y_s, int best);
void	draw_square(t_map *st_map, t_square *st_square);
/* map.c */
int		orc_map(char *map, t_map *st_map);
int		valid_map(char *map, t_map *st_map);
int		parse_map_header(char *map, t_map *st_map, int lim);
int		map_error(void);
/* map_check.c */
int		count_lines(char *map);
int		count_chars(char *map);
int		check_chars(char *map, t_map *st_map);
int		empty_line(char *map);
int		check_header(char *map);
/* matrix.c */
char	**build_array(char *buff, t_map *st_map);
int		**build_matrix_1(char **buff, t_map *st_map);
int		**build_matrix_2(int **matrix, t_map *st_map);
/* print.c */
void	print_array(char **array, int row, int col);
void	print_matrix(int **matrix, int row, int col);
void	print_header(int *li, char *em, char *ob, char *fu);
void	ft_putchar(char c);
/* utils.c */
size_t	ft_atoi(char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
int		error(void);
void	print_list(t_map *list);
/* char.c */
int		ft_issign(char c);
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_isprintable(char c);
#endif
