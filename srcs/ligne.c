/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:10:58 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/05 19:30:00 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	linebh(t_coord p1, t_coord p2, t_mv v)
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
	y = p1.y + 1;
	cumul = dy / 2 ;
	while (y <= p2.y)
	{
		cumul += dx ;
		if (cumul >= dy)
		{
			cumul -= dy ;
			x += 1 ;
		}
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
		y++;
	}
}

void	linebl(t_coord p1, t_coord p2, t_mv v)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = p1.x;
	y = p1.y;
	dx = p2.x - p1.x;
	dy = (p2.y - p1.y);
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

void	linehl(t_coord p1, t_coord p2, t_mv v)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = p1.x;
	y = p1.y;
	dx = ABS(p2.x - p1.x);
	dy = ABS(p2.y - p1.y);
	mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
	x = p1.x + 1; //? + 1 -1 et y en fonction du sence ?
	cumul = dx / 2 ;
	while (x <= p2.x)
	{
		cumul += dy ;
		if (cumul >= dx)
		{
			cumul -= dx ;
			y -= 1 ;
		}
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
		x++;
	}
}

void	linehh(t_coord p1, t_coord p2, t_mv v)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = p1.x;
	y = p1.y;
	dx = ABS(p2.x - p1.x);
	dy = ABS(p2.y - p1.y);
	mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
	y = p1.y + 1; //? + 1 -1 et y en fonction du sence ?
	cumul = dy / 2 ;
	while (y >= p2.y)
	{
		cumul += dx ;
		if (cumul >= dy)
		{
			cumul -= dy ;
			x += 1 ;
		}
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, x, y, WHITE);
		y--;
	}
}

void	line(t_coord p1, t_coord p2, t_mv v)
{
	t_coord pt;
	int dx;
	int dy;

	if (p1.x > p2.x)
	{
		pt = p1;
		p1 = p2;
		p2 = pt;
	}
	dx = ABS(p2.x - p1.x);
	dy = ABS(p2.y - p1.y);

	if (p1.y > p2.y) // Le haut
	{
		if (dx > dy)
			linehl(p1, p2, v);
		else
			linehh(p1,p2, v);
	}
	else
	{
		if (dx > dy)
			linebl(p1, p2, v);
		else
			linebh(p1,p2, v);
	}

}
