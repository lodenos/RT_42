/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:24:40 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 21:42:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_plan(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 4)
        ft_putstr_err("ERROR: Init. Object.plan.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = vector_normalize(get_vec3(line[2]));
    obj->rgba = get_color(line[3]);
    obj->type = 3;
    obj->end = 1;
}
