/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/29 14:18:35 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void line(t_fdf *fdf, t_dot *d0, t_dot *d1)
{
	int		x;
	int		y;

	x = d0->x;
	y = d0->y;
	if (fabs(d1->y - d0->y) > fabs(d1->x - d0->x))
	{
		while (d0->y > d1->y ? y >= d1->y : y <= d1->y)
		{
			x = ((y - d0->y) / (d0->y - d1->y) * (d0->x - d1->x) + d0->x);
			mlx_pixel_put(fdf->mlx->mlx_ptr, fdf->mlx->window, x, y, 0xffffff);
			d1->y > d0->y ? y++ : y--;
		}
	}
	else
	{
		while (d0->x > d1->x ? x >= d1->x : x <= d1->x)
		{
			y = ((x - d0->x) / (d0->x - d1->x) * (d0->y - d1->y) + d0->y);
			mlx_pixel_put(fdf->mlx->mlx_ptr, fdf->mlx->window, x, y, 0xffffff);
			d1->x > d0->x ? x++ : x--;
		}
	}
}

void	maxz(t_fdf *fdf)
{
	int		max;
    int     x;
    int     y;

    max = 0;
    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
        	if (DOT_Z > max)
        		max = DOT_Z;
            x++;
        }
        y++;
    }
}

void	rotation(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
        	// DOT_Y = (MAX_Y/2) + (DOT_Y - (MAX_Y/2)) * cos(OPT_X) + 
            x++;
        }
        y++;
    }
}

																			// x :
																			// y':=y*cos(L)+z*sin(L) ;
																			// z':=-y*sin(L)+z*cos(L) ;


																			// y:
																			// x'=x*cos(L)+z*sin(L);
																			// y'=y;
																			// z'=-x*sin(L)+z*cos(L);

																			// z:
																			// x'=x*cos(L)-y*sin(L);
																			// y'=x*sin(L)+y*cos(L);
																			// z'=z;


  // p->x1 = p->x;
  // p->y1 = p->y0 + (p->y - p->y0) * cos(l->a) + (p->z0 - p->z) *
  // sin(l->a);
  // p->z1 = p->z0 + (p->y - p->y0) * sin(l->a) + (p->z - p->z0) *
  // cos(l->a);

  // p->x2 = p->x0 + (p->x1 - p->x0) * cos(l->b) + (p->z1 - p->z0) *
  // sin(l->b);
  // p->y2 = p->y1;
  // p->z2 = p->z0 + (p->x0 - p->x1) * sin(l->b) + (p->z1 - p->z0) *
  // cos(l->b);

  // p->x3 = p->x0 + (p->x2 - p->x0) * cos(l->c) + (p->y0 - p->y2) *
  // sin(l->c);
  // p->y3 = p->y0 + (p->x2 - p->x0) * sin(l->c) + (p->y2 - p->y0) *
  // cos(l->c);