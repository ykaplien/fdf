/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:21:20 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 16:57:23 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_X 1200
# define WIN_Y 1200
# define BPP fdf->bpp
# define WIN_PTR fdf->win_ptr
# define MLX_PTR fdf->mlx_ptr
# define MAP_X fdf->map[xy[1]][xy[0]].x
# define MAP_Y fdf->map[xy[1]][xy[0]].y
# define MAP_Z fdf->map[xy[1]][xy[0]].z
# define MAP_C fdf->map[xy[1]][xy[0]].color
# define DOT_X fdf->dot[xy[1]][xy[0]].x
# define DOT_Y fdf->dot[xy[1]][xy[0]].y
# define DOT_Z fdf->dot[xy[1]][xy[0]].z
# define DOT_C fdf->dot[xy[1]][xy[0]].color
# define KSTL (d0->y - d1->y)
# define KSTLL (d0->x - d1->x)
# define ZOOM fdf->zoom
# define COF (3.14 / 180)
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_dot
{

	double			x;
	double			y;
	double			z;
	int				color;
}					t_dot;

typedef struct		s_fdf
{
	int				back_col;
	int				max_y;
	int				max_x;
	double			c[3];
	int				pos[2];
	double			zoom;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*window;
	int				bpp;
	t_dot			**dot;
	t_dot			**map;
}					t_fdf;

int					validation(char *map, t_fdf *fdf);
void				max_x(char *line, t_fdf *fdf);
void				open_window(t_fdf *fdf);
void				error(int error);
void				make_pixels(t_fdf *fdf);
int					event_handle(int key, t_fdf *fdf);
void				event_handle_two(int key, t_fdf *fdf);
void				event_handle_tre(int key, t_fdf *fdf);
void				event_handle_four(int key, t_fdf *fdf);
void				event_handle_five(int key, t_fdf *fdf);
void				event_handle_six(int key, t_fdf *fdf);
void				position(t_fdf *fdf, int flag);
void				zoom(t_fdf *fdf, int flag);
void				center(t_fdf *fdf);
void				rewrite(t_fdf *fdf);
void				line(t_fdf *fdf, t_dot *d0, t_dot *d1);
void				rotationx(t_fdf *fdf);
void				rotationx_rev(t_fdf *fdf);
void				rotationy(t_fdf *fdf);
void				rotationy_rev(t_fdf *fdf);
void				rotationz(t_fdf *fdf);
void				rotationz_rev(t_fdf *fdf);
void				colorchange(t_fdf *fdf, int flag);
void				decart(t_fdf *fdf, int flag);
void				validationn(int fd, int *xy, t_fdf *fdf, char *line);
void				diagonal(t_fdf *fdf, int flag);
void				gradient(t_fdf *fdf);

#endif
