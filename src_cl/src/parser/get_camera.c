/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:12:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 22:48:54 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  get_xy(t_env *e, char *str)
{
    register int    i;
    char            **tmp;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '/' && str[i] != '-')
                ft_putstr_err("ERROR: Init. Camera.resolution.char", 1);
    tmp = ft_strsplit(str, '/');
    if (ft_strlen_tab(tmp) != 2)
        ft_putstr_err("ERROR: Init. Camera.resolution.xy", 1);
    e->scn.cam.h = (size_t)atoi(tmp[0]);
    e->scn.cam.w = (size_t)atoi(tmp[1]);
    free_tab((void **)tmp);
}

void                get_camera(t_env *e, char **line)
{
    if (ft_strlen_tab(line) != 4)
        ft_putstr_err("ERROR: Init. Camera.nbr.argument", 1);
    e->scn.cam.pos = get_vec3(line[1]);
    e->scn.cam.rotate = normalize(get_vec3(line[2]));
    get_xy(e, line[3]);
}
