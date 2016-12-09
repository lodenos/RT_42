/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:32:54 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 15:45:46 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline _Bool	move_sub(_Bool ev, cl_float3 *pos, t_key key)
{
	if (key.key_space)
	{
		ev = 1;
		pos->y -= 10;
	}
	if (key.key_lshift)
	{
		ev = 1;
		pos->y += 10;
	}
	return (ev);
}

inline _Bool		move(cl_float3 *pos, t_key key)
{
	_Bool	ev;

	ev = 0;
	if (key.key_w)
	{
		ev = 1;
		pos->z += 10;
	}
	if (key.key_s)
	{
		ev = 1;
		pos->z -= 10;
	}
	if (key.key_a)
	{
		ev = 1;
		pos->x -= 10;
	}
	if (key.key_d)
	{
		ev = 1;
		pos->x += 10;
	}
	return (move_sub(ev, pos, key));
}
