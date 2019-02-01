/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:00:06 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 16:34:34 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p		*new_p(void)
{
	t_p		*list;

	if (!(list = (t_p *)malloc(sizeof(t_p))))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	list->link_h = NULL;
	list->link_v = NULL;
	return (list);
}

int		open_close_12(int option, int *fd, char *argv)
{
	if (option == 1)
	{
		*fd = open(argv, O_RDONLY);
		if (*fd == -1)
		{
			ft_putstr("Open Fail.\n");
			return (1);
		}
	}
	if (option == 2)
	{
		if (close(*fd) == -1)
			ft_putstr("Close Fail.\n");
	}
	return (0);
}

void	back_to_start_del_last(t_p **ll, t_p **nlm)
{
	*nlm = *ll;
	*ll = (*ll)->prev;
	(*ll)->next = NULL;
	free(*nlm);
	while ((*ll)->prev != NULL)
		*ll = (*ll)->prev;
}

int		range(t_rp *v)
{
	v->ll->z = ft_atoi(v->tabstr[v->x]);
	v->ll->x = v->x;
	v->ll->y = v->y;
	if (!(v->nlm = new_p()))
		return (1);
	v->ll->next = v->nlm;
	v->nlm->prev = v->ll;
	v->ll = v->ll->next;
	free(v->tabstr[v->x]);
	v->x++;
	return (0);
}

t_p		*parsing(char *argv)
{
	t_rp v;

	if ((open_close_12(1, &(v.fd), argv)) == 1)
		return (NULL);
	if (!(v.ll = new_p()))
		return (NULL);
	v.y = 0;
	while ((v.g = get_next_line(v.fd, &(v.str))) != 0)
	{
		v.x = 0;
		if (!(v.tabstr = ft_strsplit(v.str, ' ')))
			return (NULL);
		while (v.tabstr[v.x] != 0)
		{
			if (range(&v))
				return (NULL);
		}
		free(v.tabstr);
		free(v.str);
		v.y++;
	}
	if ((open_close_12(2, &(v.fd), argv)) == 1)
		return (NULL);
	back_to_start_del_last(&(v.ll), &(v.nlm));
	return (v.ll);
}
