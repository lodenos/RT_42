/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:25:56 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:10:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_camera(t_env *e, char *cam, int index)
{
    char    **data;

    data = NULL;
    if (cam)
    {
        data = ft_strsplit(cam, ' ');
        if (index == 0)
            e->cam.pos = (t_vec3){ft_atoi(data[0]), ft_atoi(data[1]),\
                ft_atoi(data[2])};
        if (index == 1)
            e->cam.dir = (t_vec3){ft_atoi(data[0]), ft_atoi(data[1]),\
                ft_atoi(data[2])};
/*        if (index == 2)
        {
            e->wid = ft_atoi(data[0]);
            e->hei = ft_atoi(data[1]);
        }*/
    }
    free(data);
}
