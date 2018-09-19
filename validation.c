/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 17:29:17 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		validation(char *map, t_fdf *fdf)
{
	int		fd;
	int		xy[2];
	char	*line;

	xy[1] = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		max_x(line, fdf);
		fdf->max_y++;
		free(line);
	}
	close(fd);
	fd = open(map, O_RDONLY);
	fdf->dot = (t_dot **)ft_memalloc(sizeof(t_dot *) * fdf->max_y);
	while (xy[1] < fdf->max_y)
	{
		fdf->dot[xy[1]] = (t_dot *)ft_memalloc(sizeof(t_dot) * fdf->max_x);
		xy[1]++;
	}
	xy[1] = 0;
	validationn(fd, xy, fdf, line);
	return (1);
}

void	validationn(int fd, int *xy, t_fdf *fdf, char *line)
{
	char	**atoi;
	char	**src;

	while (get_next_line(fd, &line) == 1)
	{
		xy[0] = 0;
		src = ft_strsplit(line, ' ');
		while (xy[0] < fdf->max_x)
		{
			DOT_X = xy[0];
			DOT_Y = xy[1];
			DOT_Z = ft_atoi_base(src[xy[0]], 10);
			if (ft_strchr(src[xy[0]], ','))
			{
				atoi = ft_strsplit(src[xy[0]], ',');
				DOT_C = ft_atoi_base(atoi[1] + 2, 16);
				ft_freearr(atoi);
			}
			xy[0]++;
		}
		ft_freearr(src);
		free(line);
		xy[1]++;
	}
}

void	max_x(char *line, t_fdf *fdf)
{
	char	**src;
	int		x;
	int		y;

	x = 0;
	y = 0;
	src = ft_strsplit(line, ' ');
	while (src[x] != NULL)
	{
		if (ft_atoi(src[x]) == 0 && src[x][0] != '0')
			error(2);
		x++;
	}
	ft_freearr(src);
	if (fdf->max_x == 0)
		fdf->max_x = x;
	else if (fdf->max_x != x)
		error(2);
}
