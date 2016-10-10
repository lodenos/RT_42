/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:29:47 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/08 19:09:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    play_scene(t_env *e, SDL_Renderer *rend)
{
    register size_t x;
    register size_t y;
    t_ray           ray;

    if (e->gpu)
        OCL_run_raytracing(e, rend);
    else
    {
        x = 0;
        if (!(e->scn.c_diff = (t_rgba *)malloc(sizeof(t_rgba) * e->scn.n_spt)))
            ft_putstr_err("ERROR: malloc error", 1);
        while (x < e->img.w)
        {
            y = 0;
            while (y < e->img.h)
            {
                camera(e->scn.cam, &ray, x, y);
                run_raytracing(e, e->scn.obj, &ray);
                pixel_put(rend, ray.rgba, x, y);
                ++y;
            }
            ++x;
        }
    }
    SDL_RenderPresent(rend);
}
