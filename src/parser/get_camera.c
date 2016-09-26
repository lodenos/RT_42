/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:12:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 19:25:51 by glodenos         ###   ########.fr       */
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
    e->cam.h = (size_t)atoi(tmp[0]);
    e->cam.w = (size_t)atoi(tmp[1]);
    free_tab((void **)tmp);
}

void                get_camera(t_env *e, char **line)
{
    if (ft_strlen_tab(line) != 5)
        ft_putstr_err("ERROR: Init. Camera.nbr.argument", 1);
    e->cam.pos = get_vec3(line[1]);
    e->cam.rotate = get_vec3(line[2]);
    e->cam.view = get_vec3(line[3]);
    get_xy(e, line[4]);
}
