/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:00:06 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 19:00:07 by jmoussu          ###   ########.fr       */
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
	int fd;
	int x;
	int y;
	int i;
	int g;
	char *str;
	char **tabstr;
	t_p *ll; // Linked list
	t_p *nlm; // New elems

	if (!(ll = new_p()))
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open Fail.\n");
		return (NULL);
	}
		y = 0;
	while ((g = get_next_line(fd, &str)) == 1)
	{
		i = 0;
		x = 0; 
		tabstr = ft_strsplit(str, ' ');
		while (tabstr[i] != 0) // SUPRIMER LE I POUR LAISSER QUE X ?
		{
			ll->x = x++;
			ll->y = y;
			ll->z = ft_atoi(tabstr[i]);
			i++;
			if (!(nlm = new_p()))
				return (NULL);
			ll->next = nlm;
			nlm->prev = ll;
			ll = ll->next;
		}
		y++;
	} // Un element en trop a suprimer ! tester avant
	return (ll);
}
