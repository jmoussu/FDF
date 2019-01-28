/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:05:08 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 19:05:10 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (-1);
}

int		error(void)
{
	ft_putstr("error\n");
	return (-1);
}
