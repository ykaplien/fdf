/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:17:29 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/29 15:17:29 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf = NULL;

	if (argc == 2)
	{
        fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
        if (validation(argv[1], fdf))
        {
            open_window(fdf);
            mlx_loop(MLX_PTR);
        }
	}
	else
		error(1);
    return (0);
}

void    error(int error)
{
    if (error == 1)
    {
        ft_putendl("usage: ./fdf map_file");
        exit(0);
    }
    else if (error == 2)
    {
        ft_putendl("invalid map!");
        exit(0);
    }
}