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

void	open_window(t_fdf *fdf)
{
	fdf->mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
    MLX_PTR = mlx_init();
    WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "YKAPLIEN");
    IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
    IMG_SRC = (int*)mlx_get_data_addr(IMG_PTR, &BPP, &LINE_SIZE, &ENDIAN);
    make_image(fdf);
    mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

int     img_ind(int x, int y, int line_size, t_fdf *fdf)
{
    int     res;

    res = ((y * line_size) + x) * RATIO + (WIN_X/2) - (MAX_X/2 * RATIO);
    return (res);
}

void    make_image(t_fdf *fdf)
{

    int     x;
    int     y;

    y = 0;
    while (y < fdf->max_y)
    {
        x = 0;
        while (x < fdf->max_x)
        {
            IMG_SRC[img_ind(x, y, LINE_SIZE, fdf)] = 0xffffff;
            x++;
        }
        y++;
    }
}