/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocnote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:12:58 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 15:09:35 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// loop hook ?

/*
** FICHIER PERSO DE DEBUG display_list.c read.c
** A suprimer ou normer avant de rendre !
*/

/*
** Test ./fdf fdf ! malloc erreur free !
** test pas de \n last ligne
** 
*/

/*
** segfault quand on apuis sur une touche avant le lansement du programe
*/

/*
** How to use leaks :
** rajouter avant le return du main 
** `while 1 ;`
**
** ./fdf map &
** leaks $(pgrep fdf)
** pkill fdf
*/

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

///////////////////////////////////

#include "fdf.h"

char	*read_file(char *arg)
{
	char	*str;
	int		fd;
	int		retgnl;

	str = NULL;
	if ((open_close_12(1, &(fd), arg)) == 1)
		return (NULL);
	while ((retgnl = get_next_line(fd, &str)) != 0)
	{
		if (retgnl < 0)
		{
			ft_putstr("ALO ALO ALO ???\n ALO ALO ALO ?? \n");
			free(str);
			return (NULL);
		}
		ft_putnbr(retgnl);
		ft_putchar('\t');
		ft_putstr(str);
		free(str);
		ft_putchar('\n');
	}
	if ((open_close_12(2, &(fd), arg)) == 1)
		return (NULL);
	return (str);
}

		// while (1)
		// {
		// 	ft_putstr(".");
		// 	usleep(7000000);
		// }
