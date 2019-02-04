/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:10:58 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/04 18:45:00 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_coord p1, t_coord p2, t_mv v)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = p1.x;
	y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
	x = p1.x + 1; //  ? + 1 -1 et y en fonction du sence ?
	cumul = dx / 2 ;
	while (x <= p2.x)
	{
		cumul += dy ;
		if (cumul >= dx)
		{
			cumul -= dx ;
			y += 1 ;
		}
    	mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
		x++;
	}
}
