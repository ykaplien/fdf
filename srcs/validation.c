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

int		validation(char *map, t_fdf *fdf)
{
	int		fd;
    int     x;
    int     y;
	char	*line;
    char    **src;
    char    *comma; // запятая

    y = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
        max_x(line,fdf);
        fdf->max_y++;
	}
    close(fd);
    fd = open(map, O_RDONLY);
    fdf->dot = (t_dot**)ft_memalloc(sizeof(t_dot*) * fdf->max_y);
    while (y < fdf->max_y)
    {
        fdf->dot[y] = (t_dot*)ft_memalloc(sizeof(t_dot) * fdf->max_x);
        y++;
    }
    y = 0;
    while (get_next_line(fd, &line) == 1)
    {
        src = ft_strsplit(line, ' ');
        x = 0;
        while (x < fdf->max_x)
        {
            fdf->dot[y][x].x = x;
            fdf->dot[y][x].y = y;
            fdf->dot[y][x].z = ft_atoi(src[x]);
            if ((comma = ft_strchr(src[x], ',')) != NULL)
                fdf->dot[y][x].color = ft_a
            x++;
        }
        y++;
    }
    return (0);
}


void	max_x(char *l, t_fdf *fdf)
{
	int 	i;
	int		max_x;

    max_x = 0;
	i = 0;
	while (l[i] != '\n')
	{
		if (l[i] > 47 && l[i] < 123 && (l[i + 1] == 32 || l[i + 1] == '\n'))
            max_x++;
        i++;
	}
    if (fdf->max_x == 0)
        fdf->max_x = max_x;
    if (fdf->max_x != max_x)
        error(2);
}