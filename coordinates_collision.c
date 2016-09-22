/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 07:23:45 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 17:10:50 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	coordinates_collision(t_obj *obj, t_ray ray)
{
	obj->norm.x = ray.ro.x + ray.rd.x * obj->det;
	obj->norm.y = ray.ro.y + ray.rd.y * obj->det;
	obj->norm.z = ray.ro.z + ray.rd.z * obj->det;
}
