/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:53 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/01 21:20:12 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define BUFF 1024
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF
# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

typedef struct	s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*link_h;
	struct s_point	*link_v;
	struct s_point	*prev;
	struct s_point	*next;
}				t_p;

typedef struct	s_range_parsing
{
	int			fd;
	int			x;
	int			y;
	int			g;
	char		*str;
	char		**tabstr;
	t_p			*ll;
	t_p			*nlm;
}				t_rp;

typedef struct	s_var_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coord			pos;
	int				t;
	int				zx1;
	int				zy1;
	int				zx2;
	int				zy2;
	int				zx3;
	int				zy3;
}				t_mv;

void			lignebl(t_coord p1, t_coord p2, t_mv v);
void			lignebh(t_coord p1, t_coord p2, t_mv v);
void			lignehl(t_coord p1, t_coord p2, t_mv v);
void			lignehh(t_coord p1, t_coord p2, t_mv v);
void			ligne(t_coord p1, t_coord p2, t_mv v);
int				usage(void);
int				error(void);
char			*read_file(char *arg);
int				valid_file(char *argv);
t_p				*parsing(char *argv);
void			display_list(t_p *list);
void			display_p(t_p *list);
int				linkall(t_p *list);
void			freelist(t_p *list);
int				open_close_12(int option, int *fd, char *argv);
int				mlx_main();

#endif
