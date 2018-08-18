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
	if (key == 65453 && OPT_ZM >= 2)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM -= 0.1;                          	// zoom -
		rewriteV2(fdf);
		findcentr(fdf);
	}
	else if (key == 65437)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY = 0;                          	// reset
		OPT_PX = 0;
		OPT_X = 0;
		OPT_Y = 0;
		OPT_Z = 1.00;
		rewriteV2(fdf);
	}
	else if (key == 65451)
	{
		OPT_ZM += 0.1;							// zoom +
		rewriteV2(fdf);
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rewriteV2(fdf);
	}
	else if (key == 65433)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY += 10.00;							// down
		rewriteV2(fdf);
	}
	else if (key == 65431)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY -= 10.00;
		rewriteV2(fdf);							// up
	}
	else if (key == 65430)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;							// left	
		rewriteV2(fdf);
	}
	else if (key == 65432)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							// right
		rewriteV2(fdf);
	}
	else if (key == 65429)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;
		OPT_PY -= 10.00;							// up left
		rewriteV2(fdf);
	}
	else if (key == 65434)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							//up right
		OPT_PY -= 10.00;
		rewriteV2(fdf);
	}
	else if (key == 65436)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 10.00;
		OPT_PY += 10.00;							// down left
		rewriteV2(fdf);
	}
	else if (key == 65435)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 10.00;							// down right
		OPT_PY += 10.00;
		rewriteV2(fdf);
	}
	else if (key == 113)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_X += 0.002;                          // rot.x +
		rotationx(fdf);
		rewrite2(fdf);
	}
	else if (key == 97)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_X -= 0.002;                          // rot.x -
		rotationx(fdf);
		rewrite2(fdf);
	}
	else if (key == 119)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Y += 0.002;                          // rot.y +
		rotationy(fdf);
		rewrite2(fdf);
	}
	else if (key == 115)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Y -= 0.002;                          // rot.y -
		rotationy(fdf);
		rewrite2(fdf);
	}
	else if (key == 101)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Z += 0.002;                          // rot.z +
		rotationz(fdf);
		rewrite2(fdf);
	}
	else if (key == 100)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_Z -= 0.002;                          // rot.z -
		rotationz(fdf);
		rewrite2(fdf);
	}
	else if (key == 65307)
	{
		exit (0);
	}
	findcentr(fdf);
	return (0);
}
