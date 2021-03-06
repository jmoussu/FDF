/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:06:20 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/04 18:30:27 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freelist(t_p *list)
{
	t_p *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
