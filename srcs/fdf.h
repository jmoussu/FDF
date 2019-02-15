/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:53 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/15 16:22:59 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

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
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					bpp;
	int					s_l;
	int					e;
	unsigned char		*img;
	void				*imgs;
	t_p					*p;
	int					h;
	float				pl;
	int					bx;
	int					by;
	int					i;
	float				z;
	struct s_var_mlx	*start;
}				t_mv;

void			linebl(t_coord p1, t_coord p2, t_mv v);
void			linebh(t_coord p1, t_coord p2, t_mv v);
void			linehl(t_coord p1, t_coord p2, t_mv v);
void			linehh(t_coord p1, t_coord p2, t_mv v);
void			line(t_coord p1, t_coord p2, t_mv v);
void			linei(t_coord p1, t_coord p2, t_mv v);

int				usage(void);
int				error(void);
int				check_params(char argc);

int				valid_file(char *argv);
int				valid_bn(char *argv);
t_p				*parsing(char *argv);
int				open_close_12(int option, int *fd, char *argv);
int				linkall(t_p *list);

void			freelist(t_p *list);

int				mlx_main(t_p *map);
void			map(t_p *p, t_mv m);

int				x(t_p *stru, t_mv m);
int				y(t_p *stru, t_mv m);
t_coord			pa(t_p *stru, t_mv m);

int				xi(t_p *stru, t_mv m);
int				yi(t_p *stru, t_mv m);
t_coord			pai(t_p *stru, t_mv m);

void			fill_pixel(uint8_t *str, int x, int y);
int				deal_key(int key, void *param);
int				deal_mouse(int key, int x, int y, void *param);

#endif
