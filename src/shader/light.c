/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 16:02:15 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj obj, t_ray *ray)
{
    diffused_light(ray, spt[0], obj);
    specular_light(ray, spt[0], obj);
}
