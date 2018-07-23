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

void	print_line(t_fdf *fdf, t_dot *p0, t_dot *p1)
{
	int 	x;
	int 	y;

	
	// printf("qwe");
	x = p0->x;
	y = p0->y;
	// printf("qwe");
	if (abs(p1->y - p0->y) > abs(p1->x - p0->x))
	{
	// printf("qwe");
		while (p0->y > p1->y ? y >= p1->y : y <= p1->y)
		{
			x = ((y - p0->y) / (p0->y - p1->y) * (p0->x - p1->x) + p0->x);
			mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, MAP_C);
			p1->y > p0->y ? y++ : y--;
		}
	}
	else
	{
		while (p0->x > p1->x ? x >= p1->x : x <= p1->x)
		{
			y = ((x - p0->x) / (p0->x - p1->x) * (p0->y - p1->y) + p0->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, MAP_C);
			p1->x > p0->x ? x++ : x--;
		}
	}
}

int 	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void line(t_fdf *fdf, int x, int y)
{
	int dx = (MAP_X_N - MAP_X >= 0 ? 1 : -1);
	int dy = (MAP_Y_N - MAP_Y >= 0 ? 1 : -1);	
	int lengthX = abs(MAP_X_N - MAP_X);
	int lengthY = abs(MAP_X_NY - MAP_Y);
	int length = max(lengthX, lengthY);
	// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
	if (length == 0)
		mlx_pixel_put(MLX_PTR, WIN_PTR, MAP_X, MAP_Y, MAP_C);
	if (lengthY <= lengthX)
		{
			int xx = MAP_X;
			// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			int yy = MAP_Y;
			int d = -lengthX;
			length++;
			// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			while(length--)
			{
				// printf("%d next-> %d\n Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
				  mlx_pixel_put(MLX_PTR, WIN_PTR, xx, yy, MAP_C);
				  xx += dx;
				  d += 2 * lengthY;
				  if (d > 0) {
						d -= 2 * lengthX;
						yy += dy;
				  }
			}
	  }
	  else
	  {
	  	// printf("%d next-> %d\n Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			int xx = MAP_X;
			int yy = MAP_Y;
			int d = - lengthY;
			length++;
			while(length--)
			{
				  mlx_pixel_put(MLX_PTR, WIN_PTR, xx, yy, MAP_C);
				  yy += dy;
				  d += 2 * lengthX;
				  if (d > 0) {
						d -= 2 * lengthY;
						xx += dx;
				  }
			}
	  	}
	}

void line_y(t_fdf *fdf, int x, int y)
{
	int dx = (MAP_Y_NX - MAP_X >= 0 ? 1 : -1);
	int dy = (MAP_Y_N - MAP_Y >= 0 ? 1 : -1);
	
	int lengthX = abs(MAP_Y_NX - MAP_X);
	int lengthY = abs(MAP_Y_N - MAP_Y);
 
	int length = max(lengthX, lengthY);

	// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
	if (length == 0)
		mlx_pixel_put(MLX_PTR, WIN_PTR, MAP_X, MAP_Y, MAP_C);
	if (lengthY <= lengthX)
		{
			int xx = MAP_X;
			// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			int yy = MAP_Y;
			int d = -lengthX;
 
			length++;
			// printf("%d next-> %d Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			while(length--)
			{
				// printf("%d next-> %d\n Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
				  mlx_pixel_put(MLX_PTR, WIN_PTR, xx, yy, MAP_C);
				  xx += dx;
				  d += 2 * lengthY;
				  if (d > 0) {
						d -= 2 * lengthX;
						yy += dy;
				  }
			}
	  }
	  else
	  {
	  	// printf("%d next-> %d\n Y:  %d next-> %d\n", MAP_X, MAP_X_N, MAP_Y, MAP_Y_N);
			int xx = MAP_X;
			int yy = MAP_Y;
			int d = - lengthY;
 
			length++;
			while(length--)
			{
				  mlx_pixel_put(MLX_PTR, WIN_PTR, xx, yy, MAP_C);
				  yy += dy;
				  d += 2 * lengthX;
				  if (d > 0) {
						d -= 2 * lengthY;
						xx += dx;
				  }
			}
	  }
}