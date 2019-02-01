/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 21:15:41 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_params(char argc)
{
	if (argc != 2)
		return (-1);
	return (0);
}

int		all_error(int argc, char **argv, char *str)
{
	if (check_params(argc) == -1)
		return (usage());
	// (void)argv;
	// (void)str;
	if (!(str = read_file(argv[1])))
		return (error());
	if (valid_file(argv[1]) == 1)
		return (error());
	else
		ft_putstr("valid file \n");
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;
	t_p		*map;

	str = NULL;
	// (void) argc;
	if (all_error(argc, argv, str))
		return (-1);
	map = parsing(argv[1]);
	linkall(map);
	display_list(map);
	freelist(map); // INUTILE LEAKS POURQUOI ? // t pa bo lol
	while (1);
	return (0);
}
