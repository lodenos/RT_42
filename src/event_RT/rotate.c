/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:46:02 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 16:29:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline _Bool	rotate_sub()
{
}

inline _Bool		rotate(cl_float3 *rotate, t_key key)
{
	int	ev;

	ev = 0;
	if (key.key_up)
	{
		ev = 1;
		rotate->x += 0.15f;
	}
	else if (key.key_down)
	{
		ev = 1;
		rotate->x += -0.15f;
	}
	else if (key.key_left)
	{
		ev = 1;
		rotate->y += -0.15;
	}
	else if (key.key_right)
	{
		ev = 1;
		rotate->y += 0.15;
	}
	else if (key.key_comma)
	{
		ev = 1;
		rotate->z += -0.15;
	}
	else if (key.key_period)
	{
		ev = 1;
		rotate->z += 0.15;
	}
	return (ev);
}
