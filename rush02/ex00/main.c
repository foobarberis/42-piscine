/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:58:02 by mbarberi          #+#    #+#             */
/*   Updated: 2022/09/17 20:58:03 by mbarberi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	size_t	n;
	t_num	*num_list;
	t_dict	*dict_list;

	n = 0;
	num_list = NULL;
	dict_list = NULL;
	if (argc < 2 || argc > 3)
		return (error());
	if (argc == 2)
		dict_list = orc_dict(dict_list, "numbers.dict");
	else
		dict_list = orc_dict(dict_list, argv[1]);
	n = ft_atoi(argv[argc - 1]);
	if (n == ERROR)
		return (error());
	num_list = ft_ntol(num_list, n);
	process_num(num_list, dict_list);
	free(num_list);
	free(dict_list);
	return (0);
}
