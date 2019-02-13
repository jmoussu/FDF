/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:17:30 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/12 17:56:26 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fill_pixel(unsigned char *str, int x, int y)
{
	int pos;

	if (x >= 1920 || y >= 1080)
		return ;
	if (x < 0 || y < 0)
		return ;
	pos = (4*x)+(4*y*1920);
	str[pos] = 255;
	str[pos+1] = 255;
	str[pos+2] = 255;
	str[pos+3] = 0; // transparence
}

void fill_0(unsigned char *str)
{
	int pos;

	pos = 0;
	while (pos != 8294395)
	{
		str[pos] = 0;
		str[pos+1] = 0;
		str[pos+2] = 0;
		str[pos+3] = 0; // transparence
		pos += 4;
	}
}
