/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:18:36 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 17:28:46 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key1(int key, t_mv *v)
{
	if (key == 53)
	{
		free(v->imgs);
		v->img = NULL;
		freelist(v->p);
		exit(0);
	}
	if (key == 49)
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
	if (key == 41)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->start->bx;
		v->by = v->start->by;
		v->h = v->start->h;
		v->z = v->start->z;
		map(v->p, *v);
	}
}

void	deal_key2(int key, t_mv *v)
{
	if (key == 34)
	{
		if (v->i == 1)
			v->i = 0;
		else
			v->i = 1;
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		map(v->p, *v);
	}
	if (key == 69)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->h = v->h + 1;
		map(v->p, *v);
	}
	if (key == 78)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->h = v->h - 1;
		map(v->p, *v);
	}
}

void	deal_key3(int key, t_mv *v)
{
	if (key == 124)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->bx + 300;
		map(v->p, *v);
	}
	if (key == 123)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->bx - 300;
		map(v->p, *v);
	}
}

int		deal_key(int key, void *param)
{
	t_mv	*v;

	v = (t_mv *)param;
	deal_key1(key, v);
	deal_key2(key, v);
	deal_key3(key, v);
	if (key == 126)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by - 300;
		map(v->p, *v);
	}
	if (key == 125)
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by + 300;
		map(v->p, *v);
	}
	return (0);
}
