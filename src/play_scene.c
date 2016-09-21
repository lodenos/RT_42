/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 10:43:19 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/20 21:49:34 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void pixel_put(SDL_Renderer *rend, t_rgb rgb, int x, int y)
{
    SDL_SetRenderDrawColor(rend, (Uint8)(rgb.red), (Uint8)(rgb.green),
            (Uint8)(rgb.blue), 255);
    SDL_RenderDrawPoint(rend, x, y);
}

static void play_object(t_env *e, SDL_Renderer *rend, int x, int y)
{
    e->cam.h = e->img.h;
    e->cam.w = e->img.w;
    camera(&e->cam, &e->ray, x, y);
    run_raytracing(e->spt, e->obj, &e->ray);
    pixel_put(rend, e->ray.rgb, x, y);
}

void        play_scene(t_env *e, SDL_Renderer* rend)
{
    int     x;
    int     y;

    x = -1;
    while (++x < e->img.w)
    {
        y = -1;
        while (++y < e->img.h)
            play_object(e, rend, x, y);
    }
    SDL_RenderPresent(rend);
}
