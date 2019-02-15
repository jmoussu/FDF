/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:38:47 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 17:04:02 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			xi(t_p *stru, t_mv m)
{
	int x;
	int dx;

	x = ((stru->x - stru->y) * 64) + m.bx;
	dx = x - 960;
	x = 960 + (dx * m.z);
	return (x);
}

int			yi(t_p *stru, t_mv m)
{
	int y;
	int dy;

	y = ((stru->y + stru->x) * 32 + m.by) - stru->z * m.h;
	dy = y - 540;
	y = 540 + (dy * m.z);
	return (y);
}

t_coord		pai(t_p *stru, t_mv m)
{
	t_coord p;

	p.x = xi(stru, m);
	p.y = yi(stru, m);
	return (p);
}
