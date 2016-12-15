/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:28:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 15:59:21 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static inline void	event_everything_sub(t_env *e)
{
	if (e->event.motion.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e->event.button.button == SDL_BUTTON_LEFT)
			e->mouse.left = 1;
		else if (e->event.button.button == SDL_BUTTON_RIGHT)
			e->mouse.right = 1;
	}
	if (e->event.motion.type == SDL_MOUSEBUTTONUP)
	{
		if (e->event.button.button == SDL_BUTTON_LEFT)
			e->mouse.left = 0;
		else if (e->event.button.button == SDL_BUTTON_RIGHT)
			e->mouse.right = 0;
	}
}

void				event_everything(t_env *e)
{
	while (e->exit)
	{
		SDL_PollEvent(&e->event);
		if (e->event.type == SDL_KEYDOWN)
			key_press(e);
		if (e->event.type == SDL_KEYUP)
			key_release(e);
		if (e->event.window.event == SDL_WINDOWEVENT_CLOSE)
			exit(0);
		if (e->event.window.event == SDL_WINDOWEVENT_MOVED)
			SDL_GetWindowPosition(e->img.win, (int *)&e->img.x,
				(int *)&e->img.y);
		if (e->event.window.event == SDL_WINDOWEVENT_RESIZED)
			window_resize(e);
		if (e->event.motion.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&e->mouse.x, &e->mouse.y);
		event_everything_sub(e);
	}
}
