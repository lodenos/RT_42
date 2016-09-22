/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 19:31:34 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/14 15:01:29 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double      plan(t_obj obj, t_ray ray)
{
    double  det;
	(void)obj;

	det = -((vecdot(&obj.rot, &ray.ro) - vecdot(&obj.rot, &obj.pos))\
			/ vecdot(&obj.rot, &ray.rd));
	if (det < 0)
        return (-1);
    return (det);
}
