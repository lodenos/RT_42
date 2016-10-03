/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:26:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/01 15:12:01 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline int   get_radius(char *str)
{
    register int    i;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
           ft_putstr_err("ERROR: Init. Object.sphere.char.radius", 1);
    return (atoi(str));
}

void                get_sphere(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 5)
        ft_putstr_err("ERROR: Init. Object.sphere.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = get_vec3(line[2]);
    obj->rgba = get_color(line[3]);
    obj->radius = get_radius(line[4]);
    obj->ft = &(sphere);
    obj->end = 1;
}
