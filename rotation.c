/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 13:44:18 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_fdf *fdf)
{
	fdf->c[0] = fdf->map[fdf->max_y / 2][fdf->max_x / 2].x;
	fdf->c[1] = fdf->map[fdf->max_y / 2][fdf->max_x / 2].y;
	fdf->c[2] = fdf->map[fdf->max_y / 2][fdf->max_x / 2].z;
}

void	rotationx(t_fdf *fdf)
{
	int		xy[2];
	double	ty;

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			ty = MAP_Y;
			MAP_Y = MAP_Y * cos(5 * COF) + MAP_Z * sin(5 * COF);
			MAP_Z = -ty * sin(5 * COF) + MAP_Z * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}

void	rotationx_rev(t_fdf *fdf)
{
	int		xy[2];
	double	ty;

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			ty = MAP_Y;
			MAP_Y = MAP_Y * cos(5 * COF) - MAP_Z * sin(5 * COF);
			MAP_Z = ty * sin(5 * COF) + MAP_Z * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}

void	decart(t_fdf *fdf, int flag)
{
	int		xy[2];

	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			MAP_X = (flag == 0) ? MAP_X - fdf->c[0] : MAP_X + fdf->c[0];
			MAP_Y = (flag == 0) ? MAP_Y - fdf->c[1] : MAP_Y + fdf->c[1];
			MAP_Z = (flag == 0) ? MAP_Z - fdf->c[2] : MAP_Z + fdf->c[2];
			xy[0]++;
		}
		xy[1]++;
	}
}

void	rotationy(t_fdf *fdf)
{
	int		xy[2];
	double	tx;

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			tx = MAP_X;
			MAP_X = MAP_X * cos(5 * COF) + MAP_Z * sin(5 * COF);
			MAP_Z = -tx * sin(5 * COF) + MAP_Z * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}
