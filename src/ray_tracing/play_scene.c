/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:29:47 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/07 02:20:05 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/* TODO Add Filter RGB sepia ... */

static inline void  *mapping(void *arg)
{
    cl_float2       pos;
    t_ray           ray;
    register size_t x;
    register size_t y;

    y = ((t_mppng *)arg)->mimg.start_y;
    while (y < ((t_mppng *)arg)->mimg.stop_y)
    {
        x = ((t_mppng *)arg)->mimg.start_x;
        while (x < ((t_mppng *)arg)->mimg.stop_x)
        {
            pos.x = (float)x;
            pos.y = (float)y;
            super_sampling(((t_mppng *)arg)->e, &ray, pos, 1);
            ((t_mppng *)arg)->e->img.img[y * ((t_mppng *)arg)->e->scn.cam.w + x] = ray.color;
            ++x;
        }
        ++y;
    }
    pthread_exit(NULL);
}

static inline void  lunch_thread_mapping(t_env *e)
{
    pthread_t   pth[e->thread];
    size_t      px;
    size_t      i;

    t_mppng     arg[e->thread];

    size_t      tmp;

    tmp = 0;
    px = e->img.h / e->thread;

    i = 0;
    while (i < e->thread)
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
    while (i < e->thread)
    {
        if (pthread_join(pth[i], NULL) == -1)
            ft_putstr_err("ERROR: thread", 1);
        ++i;
    }
}

void    *play_scene(void *arg)
{
    register float  det;
    t_ray           ray;
    size_t          id;

    ((t_env *)arg)->start = 1;
    while (((t_env *)arg)->exit)
    {
        if (event_RT((t_env *)arg) == 0)
        {
            camera(((t_env *)arg)->scn.cam, &ray, (float)((t_env *)arg)->mouse.x,
                    (float)((t_env *)arg)->mouse.y);
            det = check_object(((t_env *)arg)->obj, ray, &id, NO_MASK);
            if ((int)det == -1)
                ((t_env *)arg)->mouse.id = -1;
            else
                ((t_env *)arg)->mouse.id = (int)id;
            continue ;
        }
        fps_info(); /*----------------------------------------------------------    FPS */
        if (((t_env *)arg)->gpu)
            OCL_run_raytracing((t_env *)arg);
        else
            lunch_thread_mapping((t_env *)arg);
        push_to_window(((t_env *)arg)->img.rend, ((t_env *)arg)->img.img,
                ((t_env *)arg)->scn.cam.w, ((t_env *)arg)->scn.cam.h);
    }
    pthread_exit(NULL);
}
