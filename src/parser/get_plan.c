/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 01:24:40 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 20:12:39 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_plan(t_obj *obj, char **line)
{
    if (ft_strlen_tab(line) != 4)
        ft_putstr_err("ERROR: Init. Object.plan.nbr.argument", 1);
    obj->pos = get_vec3(line[1]);
    obj->rotate = get_vec3(line[2]);
    obj->rgba = get_color(line[3]);
    obj->ft = &(plan);
    obj->end = 1;
}
