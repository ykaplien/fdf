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

int		event_handle(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 78 && OPT_ZM > 2)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM -= 2;                          	// zoom -
		rewrite2(fdf);
	}
	else if (key == 87)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY = 0;                          	// reset
		OPT_PX = 0;
		OPT_X = 0;
		OPT_Y = 0;
		OPT_Z = 0;
		rewrite2(fdf);
	}
	else if (key == 69)
	{
		OPT_ZM += 2;							// zoom +
		rewrite2(fdf);
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rewrite2(fdf);
	}
	else if (key == 84)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY += 10.00;							// down
		rewrite2(fdf);
	}
	else if (key == 91)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY -= 10.00;
		rewrite2(fdf);							// up
	}
	else if (key == 86)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;							// left	
		rewrite2(fdf);
	}
	else if (key == 88)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							// right
		rewrite2(fdf);
	}
	else if (key == 89)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;
		OPT_PY -= 10.00;							// up left
		rewrite2(fdf);
	}
	else if (key == 92)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							//up right
		OPT_PY -= 10.00;
		rewrite2(fdf);
	}
	else if (key == 83)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;
		OPT_PY += 10.00;							// down left
		rewrite2(fdf);
	}
	else if (key == 85)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							// down right
		OPT_PY += 10.00;
		rewrite2(fdf);
	}
	else if (key == 18)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_X += 0.002;                          // rot.x +
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 12)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_X -= 0.002;                          // rot.x -
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 19)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Y += 0.002;                          // rot.y +
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 13)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Y -= 0.002;                          // rot.y -
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 20)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Z += 0.002;                          // rot.z +
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 14)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Z -= 0.002;                          // rot.z -
		rotation(fdf);
		rewrite2(fdf);
	}
	else if (key == 53)
	{
		exit (0);
	}
	findcentr(fdf);
	return (0);
}
