/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:29:47 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/14 14:11:20 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    play_scene(t_env *e, SDL_Renderer *rend)
{
    register size_t x;
    register size_t y;
    t_ray           ray;

    if (event_RT(e) == 0)
    {
        int id;
        camera(e->scn.cam, &ray, (float)e->mouse.x, (float)e->mouse.y);
        id = check_object(e->scn.obj, &ray);


        printf("Pos mouse = x %d ; y = %d\n", e->mouse.x, e->mouse.y);

        printf("Befer ID object = %d\n", id);
        if (e->scn.obj[id].det == -1)
        {
            id = -1;
            e->mouse.id = id;
        }
        else
            e->mouse.id = id;
        printf("After ID object = %d\n", id);
        return ;
    }

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
                super_sampling(e, &ray, (cl_float2){(float)x, (float)y}, 1);
                pixel_put(rend, ray.rgba, x, y);
                ++y;
            }
            ++x;
        }
    }
    /* TODO Add filter  */
    SDL_RenderPresent(rend);
}
