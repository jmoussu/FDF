/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 18:56:22 by jmoussu          ###   ########.fr       */
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
	(void)argv;
	(void)str;
	if (!(str = read_file(argv[1])))
		return (error());
	ft_putstr(str);
	// if (valid_file(str) == 1)
		// return (error());
	// if ((*t = parsing(str)) == NULL)
	// {
	// 	ft_strdel(&str);
	// 	return (error());
	// }
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (all_error(argc, argv, str))
		return (-1);
	ft_putstr("Valid file return = ");
	ft_putnbr(valid_file(argv[1]));
	ft_putchar('\n');
	// if (!(str = read_file(argv[1])))
	// 	return(error());
	return (0);
}
