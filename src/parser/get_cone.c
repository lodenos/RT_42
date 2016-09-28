/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:19:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 20:02:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_cone(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 4)
        ft_putstr_err("ERROR: Init. Object.cone.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = get_vec3(line[2]);
    obj->rgba = get_color(line[3]);
    obj->ft = &(cone);
    obj->end = 1;
}
