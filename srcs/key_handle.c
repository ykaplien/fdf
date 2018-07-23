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
	if (key == 78)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM -= 2;                          // zoom -
		rewrite(fdf);
	}
	else if (key == 69)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM += 2;							// zoom +
		rewrite(fdf);
	}
	else if (key == 84)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY += 15;							// down
		rewrite(fdf);
	}
	else if (key == 91)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY -= 15;						 	// up
		rewrite(fdf);
	}
	else if (key == 86)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 15;							// left	
		rewrite(fdf);
	}
	else if (key == 88)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 15;							// right
		rewrite(fdf);
	}
	else if (key == 89)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 15;
		OPT_PY -= 15;							// up left
		rewrite(fdf);
	}
	else if (key == 92)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 15;							//up right
		OPT_PY -= 15;
		rewrite(fdf);
	}
		else if (key == 83)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 15;
		OPT_PY += 15;							// down left
		rewrite(fdf);
	}
	else if (key == 85)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 15;							// down right
		OPT_PY += 15;
		rewrite(fdf);
	}
	else if (key == 53)
	{
		exit (0);
	}
	return (0);
}
