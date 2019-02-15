/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:26:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 17:53:20 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map(t_p *p, t_mv m)
{
	mlx_clear_window(m.mlx_ptr, m.win_ptr);
	if (m.i == 0)
	{
		while (p != NULL)
		{
			if (p->link_h != NULL)
				linei(pa(p, m), pa(p->link_h, m), m);
			if (p->link_v != NULL)
				linei(pa(p, m), pa(p->link_v, m), m);
			p = p->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			if (p->link_h != NULL)
				linei(pai(p, m), pai(p->link_h, m), m);
			if (p->link_v != NULL)
				linei(pai(p, m), pai(p->link_v, m), m);
			p = p->next;
		}
	}
	mlx_put_image_to_window((void *)&m, m.win_ptr, m.img_ptr, 0, 0);
	ft_bzero(m.img, 8294400);
}

int		mlx_main(t_p *p)
{
	static t_mv	v;
	static t_mv	start;

	v.p = p;
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 1920, 1080, "NOM DE LA FENETRE");
	v.img_ptr = mlx_new_image(v.mlx_ptr, 1920, 1080);
	if (!(v.imgs = (unsigned char*)malloc((sizeof(unsigned char) * 8294400))))
		return (error());
	v.img = v.imgs;
	v.img = (uint8_t *)mlx_get_data_addr(v.img_ptr, &(v.bpp), &(v.s_l), &(v.e));
	v.bx = 10;
	v.by = 10;
	v.h = 5;
	v.pl = 1.35;
	v.z = 1;
	v.i = 1;
	start = v;
	v.start = &start;
	map(v.p, v);
	mlx_key_hook(v.win_ptr, deal_key, (void *)&v);
	mlx_mouse_hook(v.win_ptr, deal_mouse, (void *)&v);
	mlx_loop(v.mlx_ptr);
	free(v.imgs);
	return (0);
}
