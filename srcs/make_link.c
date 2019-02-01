/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:27:15 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 16:16:35 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** xtf = x to find
** Link_v Link_h Fonction qui renvoie l'élement du bon lien ou NULL
*/

t_p		*link_h(t_p *list)
{
	int x;
	int xtf;

	x = list->x;
	xtf = x + 1;
	if (list->next->x == xtf)
		return (list->next);
	else
		return (NULL);
}

t_p		*link_v(t_p *list)
{
	int y;
	int x;
	int ytf;
	t_p *tmp;

	y = list->y;
	x = list->x;
	ytf = y + 1;
	tmp = list;
	while (tmp->next != NULL)
	{
		if (tmp->x == x && tmp->y == ytf)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->x == x && tmp->y == ytf)
		return (tmp);
	return (NULL);
}

int		linkall(t_p *list)
{
	if (list == NULL)
		return (1);
	while (list->next != NULL)
	{
		list->link_h = link_h(list);
		list->link_v = link_v(list);
		list = list->next;
	}
	while (list->prev != NULL)
		list = list->prev;
	return (0);
}
