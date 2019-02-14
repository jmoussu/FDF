/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:55:53 by jmoussu           #+#    #+#             */
/*   Updated: 2019/02/14 17:39:59 by jmoussu          ###   ########.fr       */
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
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					bpp;
	int					s_l;
	int					endian;
	unsigned char		*img;
	void				*imgs;
	t_p					*p;
	int					h;
	float				pl;
	int					bx;
	int					by;
	int					i;
	float				z;
	float				zf;
	struct s_var_mlx	*start;
	// int				zy1;
	// int				zx2;
	// int				zy2;
	// int				zx3;
	// int				zy3;
}				t_mv;

void			linebl(t_coord p1, t_coord p2, t_mv v);
void			linebh(t_coord p1, t_coord p2, t_mv v);
void			linehl(t_coord p1, t_coord p2, t_mv v);
void			linehh(t_coord p1, t_coord p2, t_mv v);
void			line(t_coord p1, t_coord p2, t_mv v);
void			line4(int x1, int y1, int x2, int y2, t_mv v);
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
int				mlx_main(t_p *map);
int				check_params(char argc);
int				x(t_p *stru, t_mv m);
int				y(t_p *stru, t_mv m);
t_coord			pa(t_p *stru, t_mv m);
int				xi(t_p *stru, t_mv m);
int				yi(t_p *stru, t_mv m);
t_coord			pai(t_p *stru, t_mv m);
void			fill_pixel(uint8_t *str, int x, int y);
void			linei(t_coord p1, t_coord p2, t_mv v);

#endif
