/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 22:07:36 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/20 11:56:55 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	play_color(t_env *e, int k, t_rgb rgb)
{
    e->img.tab[k] = rgb.blue;
    e->img.tab[++k] = rgb.green;
    e->img.tab[++k] = rgb.red;
}

static void play_objet(t_env *e, double x, double y)
{
	e->pos.x = x;
	e->pos.y = y;
    e->ray.rgb.blue = 0;
    e->ray.rgb.green = 0;
    e->ray.rgb.red = 0;
    camera(e);
    run_raytracing(e->scn.spt, e->scn.obj, &e->ray);
    play_color(e, (e->pos.x * 4 + e->pos.y * e->wid * 4), e->ray.rgb);
}

void		play_scene(t_env *e)
{
	double	x;
	double	y;

    y = -1;
    while (++y < e->hei)
    {
        x = -1;
        while (++x < e->wid)
			play_objet(e, x, y);
	}
    mlx_put_image_to_window(e->img.mlx, e->img.win, e->img.img, 0, 0);
}
