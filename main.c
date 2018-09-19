/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:17:29 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 13:42:29 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
		if (validation(argv[1], fdf))
		{
			open_window(fdf);
			mlx_loop(MLX_PTR);
		}
	}
	else
		error(1);
	return (0);
}

void	error(int error)
{
	if (error == 1)
	{
		ft_putendl("usage: ./fdf map_file");
		exit(0);
	}
	else if (error == 2)
	{
		ft_putendl("invalid map!");
		exit(0);
	}
}

void	rotationy_rev(t_fdf *fdf)
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
			MAP_X = MAP_X * cos(5 * COF) - MAP_Z * sin(5 * COF);
			MAP_Z = tx * sin(5 * COF) + MAP_Z * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}

void	rotationz(t_fdf *fdf)
{
	int		xy[2];
	double	txy[2];

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			txy[0] = MAP_X;
			txy[1] = MAP_Y;
			MAP_X = MAP_X * cos(5 * COF) - MAP_Y * sin(5 * COF);
			MAP_Y = txy[0] * sin(5 * COF) + txy[1] * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}

void	rotationz_rev(t_fdf *fdf)
{
	int		xy[2];
	double	txy[2];

	xy[1] = 0;
	center(fdf);
	decart(fdf, 0);
	while (xy[1] < fdf->max_y)
	{
		xy[0] = 0;
		while (xy[0] < fdf->max_x)
		{
			txy[0] = MAP_X;
			txy[1] = MAP_Y;
			MAP_X = MAP_X * cos(5 * COF) + MAP_Y * sin(5 * COF);
			MAP_Y = -txy[0] * sin(5 * COF) + txy[1] * cos(5 * COF);
			xy[0]++;
		}
		xy[1]++;
	}
	decart(fdf, 1);
}
