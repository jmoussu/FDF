/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:00:30 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/30 20:02:00 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_p(t_p *list)
{
	if (list == NULL)
	{
		ft_putstr("NULL\n");
		return ;
	}
	if (list->next == NULL)
		ft_putstr("\nLAST POINT\n");
	else
		ft_putstr("\nNEW POINT\n");
	ft_putstr("x = ");
	ft_putnbr(list->x);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(list->y);
	ft_putchar('\n');
	ft_putstr("z = ");
	ft_putnbr(list->z);
	ft_putchar('\n');
}

void	display_list(t_p *list)
{
	int i;

	i = 0;
	ft_putstr("\nDEBUT DE LA LISTE\n");
	while (list->next != NULL)
	{
		i++;
		display_p(list);
		ft_putstr("->PREV : ");
		display_p(list->prev);
		ft_putstr("->NEXT : ");
		display_p(list->next);
		ft_putstr("->LINK_H : ");
		display_p(list->link_h);
		ft_putstr("->LINK_V : ");
		display_p(list->link_v);
		ft_putstr("\n");
		list = list->next;
	}
	i++;
	display_p(list);
	ft_putstr("->PREV : ");
	display_p(list->prev);
	ft_putstr("->NEXT : ");
	display_p(list->next);
	ft_putstr("->LINK_H : ");
	display_p(list->link_h);
	ft_putstr("->LINK_V : ");
	display_p(list->link_v);
	ft_putstr("Le nombre de point de la liste est egale à : ");
	ft_putnbr(i);
	ft_putchar('\n');
	while (list->prev != NULL)
		list = list->prev;
}
// afficher la liste
// x y z=
// NEXT XYZ PREV XYZ LINK_H XYZ LINK_V XYZ
