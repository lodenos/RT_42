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
            ((t_mppng *)arg)->e->img.img[y * ((t_mppng *)arg)->e->scn.cam.w
                    + x] = ray.color;
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

    tmp = 0;
    px = e->img.h / THREAD;

    i = 0;
    while (i < THREAD)
    {
        arg[i].e = e;
        arg[i].mimg.start_x = 0;
        arg[i].mimg.start_y = tmp;
        tmp += px;
        arg[i].mimg.stop_x = e->img.w;
        arg[i].mimg.stop_y = tmp;

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
            det = check_object(e->obj, ray, &id);
            if (det == -1)
                e->mouse.id = -1;
            else
                e->mouse.id = id;
            continue ;
        }
        fps_info(); /*----------------------------------------------------------    FPS */
        if (e->gpu)
            OCL_run_raytracing(e, e->img.rend);
        else
        {
            if (!(e->c_diff = (unsigned int *)malloc(sizeof(unsigned int) *
                    e->scn.n_spt)))
                ft_putstr_err("ERROR: malloc error", 1);
            lunch_thread_mapping(e);
        }

        push_to_window(e->img.rend, e->img.img, e->scn.cam.w, e->scn.cam.h);
    }
    pthread_exit(NULL);
}
