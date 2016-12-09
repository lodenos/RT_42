/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_RT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:05:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 16:29:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

int					event_RT(t_env *e)
{
	int	ev;

	ev = 0;
	if (e->start)
	{
		ev = 1;
		e->start = 0;
	}
	if (e->mouse.left)
	{
		if (e->mouse.id != -1)
		{
			if (move(&e->obj[e->mouse.id].pos_a, e->key))
				ev = 1;
			if (rotate(&e->obj[e->mouse.id].pos_a, e->key))
				ev = 1;
		}
	}
	else
	{
		if (move(&e->scn.cam.pos, e->key))
			ev = 1;
		if (rotate(&e->scn.cam.rotate, e->key))
			ev = 1;
	}
	return (ev);
}
