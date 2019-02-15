/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:09:38 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 18:29:38 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_bn(char *argv)
{
	int		n;
	int		fd;
	int		size;
	char	str[BUFF];

	n = 0;
	if ((open_close_12(1, &(fd), argv)) == 1)
		return (1);
	while (1)
	{
		if ((size = read(fd, str, BUFF)) == 0)
			break ;
		if (str[size - 1] == '\n')
			n = 1;
	}
	if (n != 1)
		return (1);
	if ((open_close_12(2, &(fd), argv)) == 1)
		return (1);
	return (0);
}
