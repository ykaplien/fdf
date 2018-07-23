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
            MAP_X = (DOT_X - MAX_X/2) * OPT_ZM + WIN_X/2 + OPT_PX;
            MAP_Y = (DOT_Y - MAX_Y/2) * OPT_ZM + WIN_Y/2 + OPT_PY;
            MAP_Z = (DOT_Z - MAX_Y/2) * OPT_ZM + WIN_Y/2 + OPT_PZ;
            if (DOT_C)
                MAP_C = DOT_C;
            else
                MAP_C = 0xffffff;
            x++;
        }
        y++;
    }
    y = 0;
    while (y < MAX_Y - 1)
    {
        x = 0;
        while (x < MAX_X - 2)
        {
            printf("%d\n", x);
            line(fdf, x, y);
             
            x++;
        }
        y++;
    }
    // y = 0;
    // while (y < MAX_Y - 1)
    // {
    //     x = 0;
    //     while (x < MAX_X)
    //     {
    //         // if (y == MAX_Y && x == MAX_X)
    //         //     return;
    //         line_y(fdf, x, y);
    //         x++;
    //     }
    //     y++;
    // }
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
    OPT_ZM = 20;
    OPT_PX = 0;
    OPT_PY = 0;
    OPT_PZ = 0;
    OPT_X = 0;
    OPT_Y = 0;
    OPT_Z = 0;    
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
    // event_handle(111,fdf);
    // IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
    // IMG_SRC = (int*)mlx_get_data_addr(IMG_PTR, &BPP, &LINE_SIZE, &ENDIAN);
    // make_image(fdf);
    // check;
    // mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
    mlx_loop(MLX_PTR);
}

// void    check(t_fdf *fdf)
// {
//     int     x = 0;
//     int     y = 0;
//     while (y < WIN_Y)
//     {
//         x = 0;
//         while (x < WIN_X)
//         {
//             mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, 0xffffff);
//             x++;
//         }
//         y++;
//     }
// }



// int     img_ind(double x, double y, int line_size, t_fdf *fdf)
// {
//     int     res;
//     (void)fdf;
//     // res = (int)(((y + (WIN_Y/(8 * RATIO))) * line_size) + x) * RATIO + (WIN_X/2) - (MAX_X/2 * RATIO);
//     y = (y - MAX_Y/2) * RATIO + WIN_Y/2;
//     x = (x - MAX_X/2) * RATIO + WIN_X/2;
//     res = (y * line_size/4 + x);
//     return (res);
// }


// void    make_image(t_fdf *fdf)
// {

//     int     x;
//     int     y;

//     y = 0;
//     while (y < fdf->max_y)
//     {
//         x = 0;
//         while (x < fdf->max_x)
//         {
//             // mlx_pixel_put(MLX_PTR, WIN_PTR, );
//             IMG_SRC[img_ind(DOT_X, DOT_Y, LINE_SIZE, fdf)] = 0xffffff;
//             x++;
//         }
//         y++;
//     }
//     while (y < fdf->max_y)
//     {
//         x = 0;
//         while (x < fdf->max_x)
//         {
//             IMG_SRC[img_ind(DOT_X, DOT_Y, LINE_SIZE, fdf)] = 0xffffff;
//             x++;
//         }
//         y++;
//     }
// }
