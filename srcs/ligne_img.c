/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:09:28 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/12 17:03:44 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	linebhi(t_coord p1, t_coord p2, t_mv v)
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
	fill_pixel(v.img, x, y);
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
		fill_pixel(v.img, x, y);
		y++;
	}
}

void	linebli(t_coord p1, t_coord p2, t_mv v)
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
	fill_pixel(v.img, x, y);
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
		fill_pixel(v.img, x, y);
		x++;
	}
}

void	linehli(t_coord p1, t_coord p2, t_mv v)
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
	fill_pixel(v.img, x, y);
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
		fill_pixel(v.img, x, y);
		x++;
	}
}

void	linehhi(t_coord p1, t_coord p2, t_mv v)
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
	fill_pixel(v.img, x, y);
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
		fill_pixel(v.img, x, y);
		y--;
	}
}

void	linei(t_coord p1, t_coord p2, t_mv v)
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
			linehli(p1, p2, v);
		else
			linehhi(p1,p2, v);
	}
	else
	{
		if (dx > dy)
			linebli(p1, p2, v);
		else
			linebhi(p1,p2, v);
	}
}

// void	line4(int x1, int y1, int x2, int y2, t_mv v)
// {
// 	t_coord p1;
// 	t_coord p2;
// 	t_coord pt;
// 	int dx;
// 	int dy;

// 	p1.x = x1;
// 	p1.y = y1;
// 	p2.x = x2;
// 	p2.y = y2;
// 	if (x1 > x2)
// 	{
// 		pt = p1;
// 		p1 = p2;
// 		p2 = pt;
// 	}
// 	dx = ABS(p2.x - p1.x);
// 	dy = ABS(p2.y - p1.y);

// 	if (p1.y > p2.y) // Le haut
// 	{
// 		if (dx > dy)
// 			linehli(p1, p2, v);
// 		else
// 			linehhi(p1,p2, v);
// 	}
// 	else
// 	{
// 		if (dx > dy)
// 			linebli(p1, p2, v);
// 		else
// 			linebhi(p1,p2, v);
// 	}

// }
