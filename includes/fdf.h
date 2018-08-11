/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:21:20 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/29 15:21:20 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RATIO 2
////////////////////////////
# define WIN_X 2000
# define WIN_Y 1200
////////////////////////////
# define MAX_X fdf->max_x
# define MAX_Y fdf->max_y
# define MID_Z fdf->mid_z
/////////////////////////////
# define MAP fdf->map
# define MAP_X fdf->map[y][x].x
# define MAP_Y fdf->map[y][x].y
# define MAP_Z fdf->map[y][x].z
# define MAP_X_N fdf->map[y][x + 1].x
# define MAP_X_NY fdf->map[y][x + 1].y
# define MAP_Y_N fdf->map[y + 1][x].y
# define MAP_Y_NX fdf->map[y + 1][x].x
# define MAP_Z_N fdf->map[y][x].z
# define MAP_C fdf->map[y][x].color
////////////////////////////
# define MLX fdf->mlx
# define BPP fdf->mlx->bpp
# define WIN_PTR fdf->mlx->window
# define MLX_PTR fdf->mlx->mlx_ptr
////////////////////////////
# define DOT_X fdf->dot[y][x].x
# define DOT_Y fdf->dot[y][x].y
# define DOT_Z fdf->dot[y][x].z
# define DOT_C fdf->dot[y][x].color
////////////////////////////
# define OPT fdf->opt
# define OPT_X fdf->opt->rot_x
# define OPT_Y fdf->opt->rot_y
# define OPT_Z fdf->opt->rot_z
# define OPT_ZM fdf->opt->zoom
# define OPT_PX fdf->opt->pos_x
# define OPT_PY fdf->opt->pos_y
# define OPT_PZ fdf->opt->pos_z
/////////////////////////////
# include "../libft/libft.h"
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

typedef struct 		s_opt
{
	int				zoom;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			rot_x;
	double			rot_y;
	double			rot_z;
}					t_opt;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*window;
    int             bpp;
}					t_mlx;

typedef struct		s_fdf
{
	int				max_y;
	int				max_x;
	double			mid[3][3];
	t_mlx			*mlx;
	t_dot			**dot;
	t_dot			**map;
	t_opt			*opt;
}					t_fdf;

int					validation(char *map, t_fdf *fdf);
void	            max_x(char *line, t_fdf *fdf);
void                error(int error);
void				open_window(t_fdf *fdf);
void			    make_pixels(t_fdf *fdf);
void				line(t_fdf *fdf, t_dot *d0, t_dot *d1);
void				print_line(t_fdf *fdf, t_dot *p0, t_dot *p1);
int					event_handle(int key, t_fdf *fdf);
void			    rewrite(t_fdf *fdf);
void			    rewrite2(t_fdf *fdf);
void  			  	findcentr(t_fdf *fdf);
// void	maxz(t_fdf *fdf);
void				rotation(t_fdf *fdf);


#endif