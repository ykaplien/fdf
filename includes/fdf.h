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
# define WIN_X 1500
# define WIN_Y 1100
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_dot
{

	double			x;
	double			y;
	double			z;
	int				color;
}					t_dot;

typedef struct		s_fdf
{
	int				max_y;
	int				max_x;		
	t_dot			**dot;
}					t_fdf;

int					validation(char *map, t_fdf *fdf);
void	            max_x(char *line, t_fdf *fdf);
void                error(int error);


#endif