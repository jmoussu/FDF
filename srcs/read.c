/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:56:47 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 16:39:03 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_file(char *arg)
{
	char	*str;
	int		fd;
	int		retgnl;

	str = NULL;
	if ((open_close_12(1, &(fd), arg)) == 1)
		return (NULL);
	while ((retgnl = get_next_line(fd, &str)) != 0)
	{
		if (retgnl < 0)
		{
			free(str);
			return (NULL);
		}
		ft_putnbr(retgnl);
		ft_putchar('\t');
		ft_putstr(str);
		free(str);
		ft_putchar('\n');
	}
	if ((open_close_12(2, &(fd), arg)) == 1)
		return (NULL);
	return (str);
}
