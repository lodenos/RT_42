/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:05:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:23:31 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static int	event_mouse(t_env *e)
{
	int	ev;
	int i;

	i = 0;
	ev = 0;
	if (e->mouse.id != -1)
	{
		while (e->obj[i].end)
		{
			if (e->obj[e->mouse.id].id == e->obj[i].id)
			{
				if (move(&e->obj[i].pos_a, e->key))
					ev = 1;
				if (rotate(&e->obj[i].pos_a, e->key))
					ev = 1;
			}
			++i;
		}
	}
	return (ev);
}

int			event_rt(t_env *e)
{
	int	ev;

	ev = 0;
	if (e->start)
	{
		ev = 1;
		e->start = 0;
	}
	if (e->mouse.left)
		ev = event_mouse(e);
	else
	{
		if (move(&e->scn.cam.pos, e->key))
			ev = 1;
		if (rotate(&e->scn.cam.rotate, e->key))
			ev = 1;
	}
	return (ev);
}
