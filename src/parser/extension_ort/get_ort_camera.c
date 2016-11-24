/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ort_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:04:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/31 16:14:05 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_ort_camera(t_env *e)
{
    e->scn.cam.fov = 1;
    e->scn.cam.h = 540;
    e->scn.cam.pos = (cl_float3){0, 0, 0};
    e->scn.cam.rotate = (cl_float3){0, 0, 0};
    e->scn.cam.w = 960;
}

void                get_ort_camera(t_env *e, char **str, size_t *i)
{
    init_ort_camera(e);
    if (e->camera)
        ft_putstr_err("ERROR: camera is already initialized", 1);
    if (!str[*i])
        ft_putstr_err("ERROR: .ort camera == NULL", 1);
    if (!str[++*i] && ft_strcmp(str[*i], "{") == 0)
        ft_putstr_err("ERROR: camera {", 1);
    while (ft_strcmp(str[++*i], "}") != 0)
    {
        if (ft_strcmp(str[*i], "resolution") == 0)
            ++*i;
        else if (ft_strcmp(str[*i], "position") == 0)
            ++*i;
        else if (ft_strcmp(str[*i], "rotate") == 0)
            ++*i;
        else
            ft_putstr_err("ERROR: camera flags Unknown", 1);
    }
    e->camera = 1;
}
