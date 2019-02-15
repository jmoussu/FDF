/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 16:31:01 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		all_error(int argc, char **argv, t_p **map)
{
	if (check_params(argc) == -1)
		return (usage());
	if (valid_bn(argv[1]))
		return (error());
	if (valid_file(argv[1]) == 1)
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
	if (all_error(argc, argv, &map))
		return (1);
	mlx_main(map);
	freelist(map);
	return (0);
}
