/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:21:27 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 20:01:44 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline int   get_radius(char *str)
{
    register int    i;

    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            ft_putstr_err("ERROR: Init. Object.cylinder.char.radius", 1);
    return (atoi(str));
}

void    get_cylinder(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 5)
        ft_putstr_err("ERROR: Init. Object.cylinder.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = get_vec3(line[2]);
    obj->rgba = get_color(line[3]);
    obj->radius = get_radius(line[4]);
    obj->ft = &(cylinder);
    obj->end = 1;
}
