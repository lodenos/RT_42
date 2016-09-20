/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:19:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/19 11:09:12 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_exit(int k, t_env *e)
{
	(void)e;
	(void)k;
	exit(0);
	return (0);
}

static void	load_rt(t_env *e)
{
	e->img.mlx = mlx_init();
	e->img.win = mlx_new_window(e->img.mlx, e->wid, e->hei, TITLE);
	e->img.img = mlx_new_image(e->img.mlx, e->wid, e->hei);
	e->img.tab = mlx_get_data_addr(e->img.img, &e->img.a, &e->img.b, &e->img.c);
	mlx_hook(e->img.win, 2, 1L << 0, event_key_press, e);
	mlx_hook(e->img.win, 3, 1L << 1, event_key_release, e);
	mlx_hook(e->img.win, 17, 1L << 17, ft_exit, e);
	play_scene(e);
	mlx_loop(e->img.mlx);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	e = parser(e, ac, av);
	printf("parser ok !\n");
	load_rt(e);
	return (0);
}
