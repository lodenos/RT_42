/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_RT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:05:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/17 16:41:02 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline int   move_camera(t_cam *cam, t_key key)
{
    int     ev;

    ev = 0;
    if (key.key_w)
    {
        ev = 1;
        cam->pos.z += 30;
    }
    if (key.key_s)
    {
        ev = 1;
        cam->pos.z -= 30;
    }
    if (key.key_a)
    {
        ev = 1;
        cam->pos.x -= 30;
    }
    if (key.key_d)
    {
        ev = 1;
        cam->pos.x += 30;
    }
    if (key.key_space)
    {
        ev = 1;
        cam->pos.y -= 30;
    }
    if (key.key_lshift)
    {
        ev = 1;
        cam->pos.y += 30;
    }
    return (ev);
}

static inline int   rotate_camera(t_cam *cam, t_key key)
{
    int     ev;

    ev = 0;
    if (key.key_up)
    {
        ev = 1;
        cam->rotate.x += 0.15f;
    }
    else if (key.key_down)
    {
        ev = 1;
        cam->rotate.x += -0.15f;
    }
    else if (key.key_left)
    {
        ev = 1;
        cam->rotate.y += -0.15;
    }
    else if (key.key_right)
    {
        ev = 1;
        cam->rotate.y += 0.15;
    }
    else if (key.key_comma)
    {
        ev = 1;
        cam->rotate.z += -0.15;
    }
    else if (key.key_period)
    {
        ev = 1;
        cam->rotate.z += 0.15;
    }
    return (ev);
}









int     event_RT(t_env *e)
{
    int     ev;

    ev = 0;
    if (e->start)
    {
        ev = 1;
        e->start = 0;
    }


    if (move_camera(&e->scn.cam, e->key))
        ev = 1;
    if (rotate_camera(&e->scn.cam, e->key))
        ev = 1;




    if (e->mouse.left)
    {
        if (e->key.key_w)
            if (e->mouse.left)
                if (e->mouse.id != -1)
                {
                    ev = 1;
                    e->obj[e->mouse.id].pos.z += 100;
                }
    }
    return (ev);
}
