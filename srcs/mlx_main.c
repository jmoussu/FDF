/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:26:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/11 18:43:27 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map(t_p* p, t_mv m)
{
	while (p != NULL)
	{
		//mlx_pixel_put(m.mlx_ptr, m.win_ptr, x(p), y(p, m), WHITE);
		if (p->link_h != NULL)
		{
			line(pa(p, m), pa(p->link_h, m), m);
		}
		if (p->link_v != NULL)
		{
			line(pa(p, m), pa(p->link_v, m), m);
		}
		p = p->next;
	}
}

int	deal_key(int key, void *param)
{
	t_mv	*v;
	v = (t_mv *)param;
	if (key == 53) //ESC
		exit(0);
	if (key == 49) //Space
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
	if (key == 41) // M
	{
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		ft_putchar('M');
		// *v = *v->start; faire fonction mieux spécifique v->start n'a pas de suite segfault c'est pas une liste chainer
		v->bx = v->start->bx;
		v->by = v->start->by;
		v->h = v->start->h;
		v->z = v->start->z;
		map(v->p, *v);
	}
	if (key == 69) // +
	{
		ft_putstr("+");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->h = v->h + 1;
		map(v->p, *v);
	}
	if (key == 78) // -
	{
		ft_putstr("-");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->h = v->h - 1;
		map(v->p, *v);
	}
	if (key == 124) // ->
	{
		ft_putstr("->");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->bx + 500;
		map(v->p, *v);
	}
		if (key == 123) // <-
	{
		ft_putstr("<-");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->bx - 500;
		map(v->p, *v);
	}
		if (key == 126) // haut
	{
		ft_putstr("^\n|\n");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by - 500;
		map(v->p, *v);
	}
	if (key == 125) // bas
	{
		ft_putstr("|\nv\n");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by + 500;
		map(v->p, *v);
	}
	//ZOOM
		if (key == 116) // haut page
	{
		ft_putstr("hp");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->z = v->z + 0.1;
		map(v->p, *v);
	}
		if (key == 121) // bas page
	{
		ft_putstr("bp");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		if ((v->z) > 0.002)
			v->z = v->z - 0.08;
		map(v->p, *v);
	}
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int	deal_mouse(int key, int x, int y, void *param)
{
	static t_coord		p1;
	static t_coord		p2;

	t_mv	*v;
	v = (t_mv *)param;
	ft_putnbr(key);
	ft_putchar('\t');
	ft_putnbr(x);
	ft_putchar('\t');
	ft_putnbr(y);
	ft_putchar('\n');
	if (key == 1)
	{
		p1.x = x;
		p1.y = y;
	}
	if (key >= 2)
	{
		p2.x = x;
		p2.y = y;
		line(p1, p2, *v);
	}
	return (0);
}



int	mlx_main(t_p *p)
{
	static t_mv	v;
	static t_mv 	start;
	v.p = p;
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 1920, 1080, "NOM DE LA FENETRE"); //960 540
	v.bx = 10;
	v.by = 10;
	v.h = 5; // hauteur
	v.pl = 1.35; // plat
	v.z = 1;
	start = v;
	v.start = &start;
	map(v.p, v);
	mlx_key_hook(v.win_ptr, deal_key, (void *)&v);
	mlx_mouse_hook(v.win_ptr, deal_mouse, (void *)&v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
