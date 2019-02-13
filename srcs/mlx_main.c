/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:26:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/13 19:44:29 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map(t_p* p, t_mv m)
{
	mlx_clear_window(m.mlx_ptr, m.win_ptr);

	if (m.i == 0)
	{
		while (p != NULL)
		{
			//mlx_pixel_put(m.mlx_ptr, m.win_ptr, x(p), y(p, m), WHITE);
			if (p->link_h != NULL)
			{
				linei(pa(p, m), pa(p->link_h, m), m);
			}
			if (p->link_v != NULL)
			{
				linei(pa(p, m), pa(p->link_v, m), m);
			}
			p = p->next;
		}
	}
	else 
	{
		while (p != NULL)
		{
			//mlx_pixel_put(m.mlx_ptr, m.win_ptr, x(p), y(p, m), WHITE);
			if (p->link_h != NULL)
			{
				linei(pai(p, m), pai(p->link_h, m), m);
			}
			if (p->link_v != NULL)
			{
				linei(pai(p, m), pai(p->link_v, m), m);
			}
			p = p->next;
		}
	}
	mlx_put_image_to_window((void *)&m, m.win_ptr, m.img_ptr, 0, 0);
	bzero(m.img, 1920*1080*4);
}

int	deal_key(int key, void *param)
{
	t_mv	*v;
	v = (t_mv *)param;
	if (key == 53) //ESC
	{
		ft_putstr("Esc\n");
		exit(0);
	}
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
	if (key == 34) // I
	{
		ft_putstr("ISO");
		if (v->i == 1)
			v->i = 0;
		else
			v->i = 1;
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
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
		v->bx = v->bx + 300;
		map(v->p, *v);
	}
		if (key == 123) // <-
	{
		ft_putstr("<-");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->bx = v->bx - 300;
		map(v->p, *v);
	}
		if (key == 126) // haut
	{
		ft_putstr("^\n|\n");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by - 300;
		map(v->p, *v);
	}
	if (key == 125) // bas
	{
		ft_putstr("|\nv\n");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		v->by = v->by + 300;
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
	if (key == 2)
	{
		p2.x = x;
		p2.y = y;
		line(p1, p2, *v);
	}
	if (key == 4) 
	{
		ft_putstr("Molette up");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		if ((v->z) < 1)
			v->z = v->z * v->zf;
		if ((v->z) >= 1)
			v->z = v->z + 0.1;
		map(v->p, *v);
	}
		if (key == 5) 
	{
		ft_putstr("Molette down");
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
		if ((v->z) > 0.005)
			v->z = v->z / v->zf;
		map(v->p, *v);
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
	v.img_ptr = mlx_new_image(v.mlx_ptr, 1920, 1080);
	if(!(v.img = (unsigned char*)malloc((sizeof(char) * 1920*1080*4)))) // a free
		return (error());
	v.img =  (unsigned char*)mlx_get_data_addr(v.img_ptr, &(v.bpp), &(v.s_l), &(v.endian));
	v.img[1920*1080*4] = '\0';
	v.bx = 10;
	v.by = 10;
	v.h = 5; // hauteur
	v.pl = 1.35; // plat
	v.z = 1;
	v.zf = 1.1;
	v.i = 1;
	start = v;
	v.start = &start;
	map(v.p, v);
	mlx_key_hook(v.win_ptr, deal_key, (void *)&v);
	mlx_mouse_hook(v.win_ptr, deal_mouse, (void *)&v);
	mlx_loop(v.mlx_ptr);
	free(v.img);
	return (0);
}
