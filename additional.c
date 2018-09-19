/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 16:58:10 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colorchange(t_fdf *fdf, int flag)
{
	int		xy[2];

	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			if (flag == 0)
				fdf->map[xy[1]][xy[0]].color += 0x010101;
			else
				fdf->map[xy[1]][xy[0]].color -= 0x010101;
			xy[0]++;
		}
		xy[1]++;
	}
}

void	diagonal(t_fdf *fdf, int flag)
{
	if (flag == 0)
	{
		position(fdf, 0);
		position(fdf, 2);
		mlx_clear_window(MLX_PTR, WIN_PTR);
	}
	else if (flag == 1)
	{
		position(fdf, 1);
		position(fdf, 2);
		mlx_clear_window(MLX_PTR, WIN_PTR);
	}
	else if (flag == 2)
	{
		position(fdf, 0);
		position(fdf, 3);
		mlx_clear_window(MLX_PTR, WIN_PTR);
	}
	else if (flag == 3)
	{
		position(fdf, 1);
		position(fdf, 3);
		mlx_clear_window(MLX_PTR, WIN_PTR);
	}
}

void	gradient(t_fdf *fdf)
{
	int		color;
	int		xy[2];

	color = fdf->map[0][0].color;
	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			MAP_C = color;
			xy[0]++;
		}
		color += 0x000001;
		xy[1]++;
	}
	mlx_clear_window(MLX_PTR, WIN_PTR);
}

void	position(t_fdf *fdf, int flag)
{
	int		xy[2];

	xy[1] = 0;
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			if (flag <= 1)
			{
				fdf->pos[0] = (flag == 1) ? fdf->pos[0] + 10 : fdf->pos[0] - 10;
				MAP_X = (flag == 1) ? MAP_X + 10 : MAP_X - 10;
			}
			else
			{
				fdf->pos[1] = (flag == 3) ? fdf->pos[1] + 10 : fdf->pos[1] - 10;
				MAP_Y = (flag == 3) ? MAP_Y + 10 : MAP_Y - 10;
			}
			xy[0]++;
		}
		xy[1]++;
	}
}

int		event_handle(int key, t_fdf *fdf)
{
	if (key == 78 && fdf->zoom >= 3)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		fdf->zoom -= 2;
		zoom(fdf, 0);
		rewrite(fdf);
	}
	else if (key == 11)
	{
		fdf->back_col = (fdf->back_col == 0xFFFFFF) ? 0x000000 : 0xFFFFFF;
		rewrite(fdf);
	}
	else if (key == 15)
	{
		colorchange(fdf, 0);
		rewrite(fdf);
	}
	else if (key == 5)
	{
		gradient(fdf);
		rewrite(fdf);
	}
	else
		event_handle_two(key, fdf);
	return (0);
}
