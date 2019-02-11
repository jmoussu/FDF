/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:56:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/11 18:12:28 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x(t_p *stru, t_mv m)
{
	int x;
	int dx; 

	x = (stru->x*50)+m.bx;
	dx = x - 960;
	x = 960 + (dx * m.z);
	return (x);
}

int		y(t_p *stru, t_mv m)
{
	int y;
	int dy;

	y = ((stru->y*50+m.by)/m.pl)-stru->z*m.h;
	dy = y - 540;
	y = 540 + (dy * m.z); // try ABS
	return (y);
}

t_coord		pa(t_p *stru, t_mv m)
{
	t_coord p;
	p.x = x(stru, m);
	p.y = y(stru, m);
	return (p);
}
