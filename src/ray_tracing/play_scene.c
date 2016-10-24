/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:29:47 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/18 16:35:48 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/* TODO Add Filter RGB sepia ... */

static inline void  *mapping(void *arg)
{
    t_ray           ray;
    register size_t x;
    register size_t y;

    y = ((t_mppng *)arg)->mimg.start_y;
    while (y < ((t_mppng *)arg)->mimg.stop_y)
    {
        x = ((t_mppng *)arg)->mimg.start_x;
        while (x < ((t_mppng *)arg)->mimg.stop_x)
        {
            super_sampling(((t_mppng *)arg)->e, &ray,
                    (cl_float2){(float)x, (float)y}, 1);
            pixel_put(((t_mppng *)arg)->e->img.rend, ray.color, x, y);
            ++x;
        }
        ++y;
    }
    pthread_exit(NULL);
}

static inline void  lunch_thread_mapping(t_env *e)
{
    pthread_t   pth[THREAD];
    size_t      px;
    size_t      i;

    t_mppng     arg[THREAD];

    size_t      tmp;



//    printf("--------------------------------------------\n");


    tmp = 0;
    px = (e->img.h * e->img.w) / THREAD;

    i = 0;
    while (i < THREAD)
    {
        arg[i].e = e;
        arg[i].mimg.start_x = 0;
        arg[i].mimg.start_y = tmp / e->img.w;
        tmp += px;
        arg[i].mimg.stop_x = e->img.w;
        arg[i].mimg.stop_y = tmp / e->img.w;


//        printf("start_x = %zu ; start_y = %zu \n", arg[i].mimg.start_x, arg[i].mimg.start_y);
//        printf("stop_x = %zu ; stop_y = %zu \n", arg[i].mimg.stop_x, arg[i].mimg.stop_y);


        if (pthread_create(&pth[i], NULL, &mapping, (void *)&arg[i]) == -1)
            ft_putstr_err("ERROR: thread", 1);
        ++i;
    }
    i = 0;
    while (i < THREAD)
    {
        if (pthread_join(pth[i], NULL) == -1)
            ft_putstr_err("ERROR: thread", 1);
        ++i;
    }
}

void    *play_scene(t_env *e)
{
    register float  det;
    t_ray           ray;
    size_t          id;

    e->start = 1;
    while (e->exit)
    {
        if (event_RT(e) == 0)
        {
            camera(e->scn.cam, &ray, (float)e->mouse.x, (float)e->mouse.y);
            det = check_object(e->scn.obj, ray, &id);
            if (det == -1)
                e->mouse.id = -1;
            else
                e->mouse.id = id;
            continue ;
        }
        if (e->gpu)
            OCL_run_raytracing(e, e->img.rend);
        else
        {
            fps_info(); /*----------------------------------------------------------    FPS */
            if (!(e->scn.c_diff = (unsigned int *)malloc(sizeof(unsigned int) *
                    e->scn.n_spt)))
                ft_putstr_err("ERROR: malloc error", 1);
            lunch_thread_mapping(e);
        }
        SDL_RenderPresent(e->img.rend);
    }
    pthread_exit(NULL);
}
