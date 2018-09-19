/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/17 17:07:18 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	event_handle_two(int key, t_fdf *fdf)
{
	if (key == 17)
	{
		colorchange(fdf, 1);
		rewrite(fdf);
	}
	else if (key == 89)
	{
		diagonal(fdf, 0);
		rewrite(fdf);
	}
	else if (key == 92)
	{
		diagonal(fdf, 1);
		rewrite(fdf);
	}
	else if (key == 83)
	{
		diagonal(fdf, 2);
		rewrite(fdf);
	}
	else
		event_handle_tre(key, fdf);
}

void	event_handle_tre(int key, t_fdf *fdf)
{
	if (key == 85)
	{
		diagonal(fdf, 3);
		rewrite(fdf);
	}
	else if (key == 69)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		fdf->zoom += 2;
		zoom(fdf, 1);
		rewrite(fdf);
	}
	else if (key == 84)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		position(fdf, 3);
		rewrite(fdf);
	}
	else
		event_handle_four(key, fdf);
}

void	event_handle_four(int key, t_fdf *fdf)
{
	if (key == 91)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		position(fdf, 2);
		rewrite(fdf);
	}
	else if (key == 86)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		position(fdf, 0);
		rewrite(fdf);
	}
	else if (key == 88)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		position(fdf, 1);
		rewrite(fdf);
	}
	else
		event_handle_five(key, fdf);
}

void	event_handle_five(int key, t_fdf *fdf)
{
	if (key == 12)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationx(fdf);
		rewrite(fdf);
	}
	else if (key == 18)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationx_rev(fdf);
		rewrite(fdf);
	}
	else if (key == 13)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationy(fdf);
		rewrite(fdf);
	}
	else
		event_handle_six(key, fdf);
}

void	event_handle_six(int key, t_fdf *fdf)
{
	if (key == 19)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationy_rev(fdf);
		rewrite(fdf);
	}
	else if (key == 14)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationz(fdf);
		rewrite(fdf);
	}
	else if (key == 20)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotationz_rev(fdf);
		rewrite(fdf);
	}
	else if (key == 53)
	{
		free(fdf);
		exit(0);
	}
}
