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

int		validation(char *map, t_fdf *fdf) {
    int fd;
    int x;
    int y;
    char **atoi;
    char **src;
    char *line;

    x = 0;
    y = 0;
    fd = open(map, O_RDONLY);
    while (get_next_line(fd, &line) == 1)
    {
        max_x(line, fdf);
        fdf->max_y++;
    }
    close(fd);
    fd = open(map, O_RDONLY);
    fdf->dot = (t_dot **)ft_memalloc(sizeof(t_dot *) * fdf->max_y);
    while (y < fdf->max_y)
    {
        fdf->dot[y] = (t_dot *)ft_memalloc(sizeof(t_dot) * fdf->max_x);
        y++;
    }
    y = 0;
    while (get_next_line(fd, &line) == 1)
    {
        x = 0;
        src = ft_strsplit(line, ' ');
        while (x < fdf->max_x)
        {
            fdf->dot[y][x].x = x;
            fdf->dot[y][x].y = y;
            fdf->dot[y][x].z = ft_atoi_base(src[x], 10);
            if (ft_strchr(src[x], ','))
            {
                atoi = ft_strsplit(src[x], ',');
                fdf->dot[y][x].color = ft_atoi_base(atoi[1] + 2, 16);
            }
            x++;
        }
        y++;
    }
    return (1);
}

void    max_x(char *line, t_fdf *fdf)
{
    char **src;
    int x;
    int y;

    x = 0;
    y = 0;
    src = ft_strsplit(line, ' ');
    while (src[x] != NULL)
    {
            if (ft_atoi(src[x]) == 0 && src[x][0] != '0')
                error(2);
        x++;
    }
    if (fdf->max_x == 0)
        fdf->max_x = x;
    else if (fdf->max_x != x)
        error(2);
}
