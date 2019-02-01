/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 22:19:33 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_params(char argc)
{
	if (argc != 2)
		return (-1);
	return (0);
}

int		all_error(int argc, char **argv, char *str, t_p **map)
{
	if (check_params(argc) == -1)
		return (usage());
	if (valid_file(argv[1]) == 1)
		return (error());
	if (!(str = read_file(argv[1])))
		return (error());
	else
		ft_putstr("valid file \n");
	if ((*map = parsing(argv[1])) == NULL)
		return (error());
	if ((linkall(*map)))
		return (error());
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;
	t_p		*map;

	str = NULL;
	map = NULL;
	if (all_error(argc, argv, str, &map))
		return (1);
	display_list(map);
	mlx_main();
	freelist(map); // INUTILE LEAKS POURQUOI ? (avant d'use mlx aussi)
	// while (1); //Leaks Usage
	return (0);
}
