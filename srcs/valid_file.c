/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:57:23 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 16:36:25 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_int(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		count_nb(char *str)
{
	char	**tabstr;
	int		i;

	i = 0;
	if (!(tabstr = ft_strsplit(str, ' ')))
		return (-1);
	while (tabstr[i] != 0)
	{
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
	return (i);
}

/*
** Mini 2 ligne et / ou 2 colonne ? ! ?
*/

int		valid_nb(char *str)
{
	static int	c = -8;

	if (c == -8)
	{
		c = count_nb(str);
		if (c <= 0)
			return (1);
	}
	if (c != count_nb(str))
		return (1);
	return (0);
}

int		valid_file(char *argv)
{
	int		g;
	int		fd;
	char	*str;
	int		vi;
	int		vn;

	if ((open_close_12(1, &(fd), argv)) == 1)
		return (1);
	while ((g = get_next_line(fd, &str)) == 1)
	{
		vi = valid_int(str);
		vn = valid_nb(str);
		if (vi == 1)
			return (1);
		if (vn == 1)
			return (1);
		free(str);
	}
	if ((open_close_12(2, &(fd), argv)) == 1)
		return (1);
	return (0);
}
