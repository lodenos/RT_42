/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_RT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:05:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/14 16:19:19 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

int     event_RT(t_env *e)
{
    int     ev;

    ev = 0;
    if (e->start)
    {
        ev = 1;
        e->start = 0;
    }
    if (e->key.key_space)
    {
        ev = 1;
        e->scn.cam.pos.y -= 10;
        e->scn.cam.view.y -= 10;
    }

    if (e->key.key_w)
    {
        ev = 1;
        e->scn.cam.pos.z += 50;
        e->scn.cam.view.z += 50;
    }
    if (e->key.key_s)
    {
        ev = 1;
        e->scn.cam.pos.z -= 50;
        e->scn.cam.view.z -= 50;
    }





    if (e->mouse.left)
    {
        if (e->key.key_w)
            if (e->mouse.left)
                if (e->mouse.id != -1)
                {
                    ev = 1;
                    e->scn.obj[e->mouse.id].pos.z += 100;
                }
        ft_putstr("LOL left\n");
    }
    return (ev);
}
