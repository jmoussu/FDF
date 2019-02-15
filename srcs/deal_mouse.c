/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:18:20 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 14:27:08 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_mouse1(int key, t_mv *v)
{
	if (key == 4)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		if ((v->z) < 7)
			v->z = v->z * 1.1;
		map(v->p, *v);
	}
	if (key == 5)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		if ((v->z) > 0.005)
			v->z = v->z / 1.1;
		map(v->p, *v);
	}
}

int		deal_mouse(int key, int x, int y, void *param)
{
	static	t_coord		p1;
	static	t_coord		p2;
	t_mv				*v;

	v = (t_mv *)param;
	if (key == 1)
	{
		p1.x = x;
		p1.y = y;
	}
	if (key == 2)
	{
		p2.x = x;
		p2.y = y;
		line(p1, p2, *v);
	}
	deal_mouse1(key, v);
	return (0);
}
