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
	if (key == 65453)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM -= 2;
		rewrite(fdf);
	}
	else if (key == 65451)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_ZM += 2;
		rewrite(fdf);
	}
	else if (key == 65433)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY += 15;
		rewrite(fdf);
	}
	else if (key == 65431)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PY -= 15;
		rewrite(fdf);
	}
	else if (key == 65430)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX -= 15;
		rewrite(fdf);
	}
	else if (key == 65432)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		OPT_PX += 15;
		rewrite(fdf);
	}
	return (0);
}
