/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:26:11 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/05 19:34:00 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	t_mv	*v;
	v = (t_mv *)param;
	if (key == 53)
		exit(0);
	if (key == 8)
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
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

int	mlx_main()
{
	t_mv	v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 500, 500, "NOM DE LA FENETRE");
	mlx_pixel_put(v.mlx_ptr, v.win_ptr, 250, 250, WHITE);
	mlx_key_hook(v.win_ptr, deal_key, (void *)&v);
	mlx_mouse_hook(v.win_ptr, deal_mouse, (void *)&v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
