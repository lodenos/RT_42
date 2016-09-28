/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:33 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 01:07:53 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void torus(register t_obj *obj, register t_ray ray)
{
    register t_evo  evo;

    (void)evo;
    (void)ray;
    obj->det = -1;
}