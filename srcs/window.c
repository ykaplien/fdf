/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                             :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:17:29 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/29 15:17:29 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    rewrite(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
            // MAP_X = (DOT_X - MAX_X/2) * OPT_ZM + WIN_X/2 + OPT_PX;
            // MAP_Y = (DOT_Y - MAX_Y/2) * OPT_ZM + WIN_Y/2 + OPT_PY;
            // MAP_Z = (DOT_Z - MAX_Y/2) * OPT_ZM + WIN_Y/2 + OPT_PZ;
            MAP_X = (DOT_X - MAX_X/2) + WIN_X/2 + OPT_PX;
            MAP_Y = (DOT_Y - MAX_Y/2) + WIN_Y/2 + OPT_PY;
            MAP_Z = (DOT_Z - MAX_Y/2) + WIN_Y/2 + OPT_PZ;
            if (DOT_C)
                MAP_C = DOT_C;
            else
                MAP_C = 0xffffff;
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X - 1)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y][x + 1]);
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y - 1)
    {
        x = 0;
        while (x < MAX_X)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y + 1][x]);
            x++;
        }
        y++;
    }
}

void    rewriteV2(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X)
        {
            MAP_X = (MAP_X + OPT_PX) * OPT_ZM;
            MAP_Y = (MAP_Y + OPT_PY) * OPT_ZM;
            MAP_Z = (MAP_Z + OPT_PZ) * OPT_ZM;
            MAP_C = MAP_C;
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X - 1)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y][x + 1]);
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y - 1)
    {
        x = 0;
        while (x < MAX_X)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y + 1][x]);
            x++;
        }
        y++;
    }
}

void    rewrite2(t_fdf *fdf)
{
    int     x;
    int     y;

    y = 0;
    while (y < MAX_Y)
    {
        x = 0;
        while (x < MAX_X - 1)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y][x + 1]);
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y - 1)
    {
        x = 0;
        while (x < MAX_X)
        {
            line(fdf, &fdf->map[y][x], &fdf->map[y + 1][x]);
            x++;
        }
        y++;
    }
}

void    make_pixels(t_fdf *fdf)
{
    int     y;

    y = 0;
    MAP = (t_dot **)ft_memalloc(sizeof(t_dot *) * fdf->max_y);
    while (y < fdf->max_y)
    {
        MAP[y] = (t_dot *)ft_memalloc(sizeof(t_dot) * fdf->max_x);
        y++;
    }
    rewrite(fdf);
}

void    opt_init(t_fdf *fdf)
{
    OPT = (t_opt *)ft_memalloc(sizeof(t_opt));
    OPT_ZM = 1.00;
    OPT_PX = 0;
    OPT_PY = 0;
    OPT_PZ = 0;
    OPT_X = 0.00;
    OPT_Y = 0.00;
    OPT_Z = 0.00;    
}

void    open_window(t_fdf *fdf)
{
    MLX = (t_mlx *)ft_memalloc(sizeof(t_mlx));
    MAP = (t_dot **)ft_memalloc(sizeof(t_dot *) * fdf->max_y);
    opt_init(fdf);
    MLX_PTR = mlx_init();
    WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "YKAPLIEN FDF");
    make_pixels(fdf);
    mlx_hook(WIN_PTR, 2, 5, event_handle, fdf);
    mlx_loop(MLX_PTR);
}
