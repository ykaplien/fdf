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

void    line(t_fdf *fdf, t_dot *d0, t_dot *d1)
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
			mlx_pixel_put(fdf->mlx->mlx_ptr, fdf->mlx->window, x, y, 0x28FA9F);
			d1->y > d0->y ? y++ : y--;
		}
	}
	else
	{
		while (d0->x > d1->x ? x >= d1->x : x <= d1->x)
		{
			y = ((x - d0->x) / (d0->x - d1->x) * (d0->y - d1->y) + d0->y);
			mlx_pixel_put(fdf->mlx->mlx_ptr, fdf->mlx->window, x, y, 0xFF169F);
			d1->x > d0->x ? x++ : x--;
		}
	}
}

void	rotationx(t_fdf *fdf)
{
    int     x;
    int     y;
    double  xx;
    double  yy;
    double  zz;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
            xx = MAP_X;            
            yy = MAP_Y;
            zz = MAP_Z;

            MAP_Y = fdf->mid[1][2] + (yy - fdf->mid[1][2]) * cos(OPT_X) + (fdf->mid[2][2] - zz) * sin(OPT_X);
            MAP_Z = fdf->mid[2][2] + (yy - fdf->mid[1][2]) * sin(OPT_X) + (zz - fdf->mid[2][2]) * cos(OPT_X);
            x++;               
        }
        y++;
    }
}

void    rotationy(t_fdf *fdf)
{
    int     x;
    int     y;
    double  xx;
    double  yy;
    double  zz;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
            xx = MAP_X;            
            yy = MAP_Y;
            zz = MAP_Z;
            MAP_X = fdf->mid[0][2] + (xx - fdf->mid[0][2]) * cos(OPT_Y) + (zz - fdf->mid[2][2]) * sin(OPT_Y);
            MAP_Z = fdf->mid[2][2] + (fdf->mid[0][2] - xx) * sin(OPT_Y) + (zz - fdf->mid[2][2]) * cos(OPT_Y);
            x++;
        }
        y++;
    }
}

void    rotationz(t_fdf *fdf)
{
    int     x;
    int     y;
    double  xx;
    double  yy;
    double  zz;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
            xx = MAP_X;            
            yy = MAP_Y;
            zz = MAP_Z;            
            MAP_X = fdf->mid[0][2] + (xx - fdf->mid[0][2]) * cos(OPT_Z) + (fdf->mid[1][2] - yy) * sin(OPT_Z);
            MAP_Y = fdf->mid[1][2] + (xx- fdf->mid[0][2]) * sin(OPT_Z) + (yy - fdf->mid[1][2]) * cos(OPT_Z);
            x++;
        }
        y++;
    }
}



void    findcentr(t_fdf *fdf)
{
    int     yx[2];
    // double  fdf->mid[3][3];
                                           //   x -> min  max   mid
                                           //   y -> min  max   mid
                                           //   z -> min  max   mid
    // ft_bzero(mid, sizeof(double) * 9);
    yx[0] = 0;
    while (yx[0] < MAX_Y)
    {
        yx[1] = 0;
        while (yx[1] < MAX_X)
        {
            if (fdf->map[yx[0]][yx[1]].x < fdf->mid[0][0])
                fdf->mid[0][0] = fdf->map[yx[0]][yx[1]].x;
            else if (fdf->map[yx[0]][yx[1]].x > fdf->mid[0][1])
                fdf->mid[0][1] = fdf->map[yx[0]][yx[1]].x;                    
            if (fdf->map[yx[0]][yx[1]].y < fdf->mid[1][0])
                fdf->mid[1][0] = fdf->map[yx[0]][yx[1]].y;
            else if (fdf->map[yx[0]][yx[1]].y > fdf->mid[1][1])
                fdf->mid[1][1] = fdf->map[yx[0]][yx[1]].y;
            if (fdf->map[yx[0]][yx[1]].x < fdf->mid[2][0])
                fdf->mid[2][0] = fdf->map[yx[0]][yx[1]].x;
            else if (fdf->map[yx[0]][yx[1]].x > fdf->mid[2][1])
                fdf->mid[2][1] = fdf->map[yx[0]][yx[1]].x;
            yx[1]++;
        }
        yx[0]++;
    }
    fdf->mid[0][2] = (fdf->mid[0][1] - fdf->mid[0][0]) / 2;
    fdf->mid[1][2] = (fdf->mid[1][1] - fdf->mid[1][0]) / 2;
    fdf->mid[2][2] = (fdf->mid[2][1] - fdf->mid[2][0]) / 2;
    printf(" X -> MIN: %f MAX: %f MID: %f\n", fdf->mid[0][0], fdf->mid[0][1], fdf->mid[0][2]);
    printf(" Y -> MIN: %f MAX: %f MID: %f\n", fdf->mid[1][0], fdf->mid[1][1], fdf->mid[1][2]);
    printf(" Z -> MIN: %f MAX: %f MID: %f\n", fdf->mid[2][0], fdf->mid[2][1], fdf->mid[2][2]);
}