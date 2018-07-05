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
# define RATIO 10
# define MAX_X fdf->max_x
# define MAX_Y fdf->max_y
# define WIN_X 900
# define WIN_Y 900
# define WIN_PTR fdf->mlx->window
# define IMG_PTR fdf->mlx->image
# define IMG_SRC fdf->mlx->image_src
# define MLX_PTR fdf->mlx->mlx_ptr
# define BPP fdf->mlx->bpp
# define LINE_SIZE fdf->mlx->line_size
# define ENDIAN fdf->mlx->endian
# define DOT_X fdf->dot[y][x].x
# define DOT_Y fdf->dot[y][x].y
# define DOT_Z fdf->dot[y][x].z
# define DOT_C fdf->dot[y][x].color
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

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*window;
    void            *image;
    int             *image_src;
    int             bpp;
    int             line_size;
    int             endian;
}					t_mlx;

typedef struct		s_fdf
{
	int				max_y;
	int				max_x;
	t_mlx			*mlx;
	t_dot			**dot;
}					t_fdf;

int					validation(char *map, t_fdf *fdf);
void	            max_x(char *line, t_fdf *fdf);
void                error(int error);
void				open_window(t_fdf *fdf);
int                 img_ind(double x, double y, int line_size, t_fdf *fdf);
void                make_image(t_fdf *fdf);


#endif