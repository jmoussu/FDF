/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:00:06 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/31 18:15:12 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

// crée la structure 
t_p		*new_p(void)
{
	t_p		*list;

	if (!(list = (t_p *)malloc(sizeof(t_p))))
		return (0);
	list->next = NULL;
	list->prev = NULL;
	list->link_h = NULL;
	list->link_v	 = NULL;
	return (list);
}

t_p		*parsing(char *argv)
{
	// int fd;
	// int x;
	// int y;
	// int g;
	// char *str;
	// char **tabstr;
	// t_p *ll; // Linked list
	// t_p *nlm; // New elems
	t_rp v;

	if (!(v.ll = new_p()))
		return (NULL);
	v.fd = open(argv, O_RDONLY);
	if (v.fd == -1)
	{
		ft_putstr("Open Fail.\n");
		return (NULL);
	}
		v.y = 0;
	while ((v.g = get_next_line(v.fd, &(v.str))) != 0)
	{
		v.x = 0; 
		if (!(v.tabstr = ft_strsplit(v.str, ' '))) // FREE ?? STR SPLIT
			return (NULL);
		while (v.tabstr[v.x] != 0) // SUPRIMER LE I POUR LAISSER QUE X ?
		{
			v.ll->z = ft_atoi(v.tabstr[v.x]);
			v.ll->x = v.x;
			v.ll->y = v.y;
			if (!(v.nlm = new_p()))
				return (NULL);
			v.ll->next = v.nlm;
			v.nlm->prev = v.ll;
			v.ll = v.ll->next;
			free(v.tabstr[v.x]);
			v.x++;
			//Free l'interieur de la tab avec une fonction maybe
		}
		free(v.tabstr);
		free(v.str);
		v.y++;
	}
	if (close(v.fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (NULL);
	}
	v.nlm = v.ll;
	v.ll = v.ll->prev; // supression de la structure en trop ! FREE ICI !
	v.ll->next = NULL;
	free(v.nlm);
	while (v.ll->prev != NULL)
		v.ll = v.ll->prev;
	return (v.ll);
}
