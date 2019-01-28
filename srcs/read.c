/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:56:47 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 18:56:50 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

char	*read_file(char *arg)
{
	char	*str;
	int		fd;
	int 	retgnl;

	str = NULL;
	// if (!(str = (char *)malloc(sizeof(char) * BUFF)))
		// return (NULL);
	// ft_bzero(str, BUFF);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_strdel(&str);
		return (NULL);
	}
	while ((retgnl = get_next_line(fd, &str)) != 0)
	{
		if (retgnl < 0)
		{
			ft_strdel(&str);
			return (NULL);
		}
		ft_putnbr(retgnl);
		ft_putchar('\t');
		ft_putstr(str);
		free(str);
		ft_putchar('\n');
	}
	if (close(fd) == -1)
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (str);
}
