/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 17:08:28 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_fdf *fdf, t_dot *d0, t_dot *d1)
{
	int		xy[2];

	xy[0] = d0->x;
	xy[1] = d0->y;
	if (fabs(d1->y - d0->y) > fabs(d1->x - d0->x))
		while (d0->y > d1->y ? xy[1] >= d1->y : xy[1] <= d1->y)
		{
			xy[0] = ((xy[1] - d0->y) / KSTL * (d0->x - d1->x) + d0->x);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], d0->color);
			d1->y > d0->y ? xy[1]++ : xy[1]--;
		}
	else
		while (d0->x > d1->x ? xy[0] >= d1->x : xy[0] <= d1->x)
		{
			xy[1] = ((xy[0] - d0->x) / KSTLL * (d0->y - d1->y) + d0->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], d0->color);
			d1->x > d0->x ? xy[0]++ : xy[0]--;
		}
}

void	open_window(t_fdf *fdf)
{
	make_pixels(fdf);
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "YKAPLIEN FDF");
	mlx_hook(WIN_PTR, 2, 5, event_handle, fdf);
	mlx_loop(MLX_PTR);
	fdf->back_col = 0x000000;
	rewrite(fdf);
}

void	rewrite(t_fdf *fdf)
{
	int		xy[2];

	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x - 1)
		{
			line(fdf, &fdf->map[xy[1]][xy[0]], &fdf->map[xy[1]][xy[0] + 1]);
			xy[0]++;
		}
		xy[1]++;
	}
	xy[1] = 0;
	while (xy[1] < fdf->max_y - 1)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			line(fdf, &fdf->map[xy[1]][xy[0]], &fdf->map[xy[1] + 1][xy[0]]);
			xy[0]++;
		}
		xy[1]++;
	}
}

void	make_pixels(t_fdf *fdf)
{
	int		xy[2];

	xy[1] = 0;
	fdf->zoom = 3;
	fdf->map = (t_dot **)ft_memalloc(sizeof(t_dot *) * fdf->max_y);
	while (xy[1] < fdf->max_y)
	{
		fdf->map[xy[1]] = (t_dot *)ft_memalloc(sizeof(t_dot) * fdf->max_x);
		xy[1]++;
	}
	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			MAP_X = (DOT_X - fdf->max_x / 2) * ZOOM + WIN_X / 2 + fdf->pos[0];
			MAP_Y = (DOT_Y - fdf->max_y / 2) * ZOOM + WIN_Y / 2 + fdf->pos[1];
			MAP_Z = (DOT_Z - fdf->max_y / 2) * ZOOM + WIN_Y / 2;
			MAP_C = DOT_C;
			xy[0]++;
		}
		xy[1]++;
	}
}

void	zoom(t_fdf *fdf, int flag)
{
	int		xy[2];

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			if (flag == 0)
			{
				fdf->map[xy[1]][xy[0]].x *= 0.90;
				fdf->map[xy[1]][xy[0]].y *= 0.90;
			}
			else
			{
				fdf->map[xy[1]][xy[0]].x *= 1.10;
				fdf->map[xy[1]][xy[0]].y *= 1.10;
			}
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}
