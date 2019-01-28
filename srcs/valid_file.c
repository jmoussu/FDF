/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:57:23 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 18:57:25 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		valid_int(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		count_nb(char *str)
{
	char **tabstr;
	int i;

	i = 0;
	tabstr = ft_strsplit(str, ' ');
	while (tabstr[i] != 0)
		i++;
	return (i);
}
// Mini 2 ligne et / ou 2 colonne ? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ?
int		valid_nb(char *str)
{
	static int	c = -8;

	if (c == -8) // Rentre seulement a la premiere ocurence
	{
		c = count_nb(str);
		if (c <= 0)
			return (1); // 1
	}
	if (c != count_nb(str))
		return (1); // 1
	return (0); // 0
}

int		valid_file(char *argv)
{
	int		g;
	int		fd;
	char	*str;
	int vi;
	int vn;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open Fail.\n");
		return (1);
	}
	while ((g = get_next_line(fd, &str)) == 1)
	{
		vi = valid_int(str);
		vn = valid_nb(str);
		if (vi == 1) // fonction qui vérifie que la str comporte que des chifre ou space!
			return (1);
		if (vn == 1)// fonction qui vérifie que toute les ligne on le meme combre de int
			return (1);

		// ft_putnbr(vi);
		// ft_putchar(' ');
		// ft_putnbr(vn);
		// ft_putchar('\t');
		// ft_putstr(str);
		// ft_putchar('\n');

	}
	if (g == -1)
	{
		return (1);
		ft_putstr("GNL ERROR\n");
	}
	if (close(fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (1);
	}
	return (0);
}
