/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:50:18 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 12:58:19 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	key_release(t_env *e)
{
	if (e->event.key.keysym.sym == SDLK_UP)
		e->key.key_up = 0;
	else if (e->event.key.keysym.sym == SDLK_DOWN)
		e->key.key_down = 0;
	else if (e->event.key.keysym.sym == SDLK_RIGHT)
		e->key.key_right = 0;
	else if (e->event.key.keysym.sym == SDLK_LEFT)
		e->key.key_left = 0;
	else if (e->event.key.keysym.sym == SDLK_PERIOD)
		e->key.key_period = 0;
	else if (e->event.key.keysym.sym == SDLK_COMMA)
		e->key.key_comma = 0;
	else if (e->event.key.keysym.sym == SDLK_w)
		e->key.key_w = 0;
	else if (e->event.key.keysym.sym == SDLK_s)
		e->key.key_s = 0;
	else if (e->event.key.keysym.sym == SDLK_SPACE)
		e->key.key_space = 0;
	else if (e->event.key.keysym.sym == SDLK_LSHIFT)
		e->key.key_lshift = 0;
	else if (e->event.key.keysym.sym == SDLK_d)
		e->key.key_d = 0;
	else if (e->event.key.keysym.sym == SDLK_a)
		e->key.key_a = 0;
}
