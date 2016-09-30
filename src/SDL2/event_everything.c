/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:28:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/29 14:06:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    event_everything(t_env *e)
{
    SDL_WaitEvent(&e->event);

    if (e->event.type == SDL_KEYDOWN)
        key_press(e);

    if (e->event.type == SDL_KEYUP)
        key_release(e);

    if (e->event.window.event == SDL_WINDOWEVENT_CLOSE)
        e->exit = 0;

    if (e->event.window.event == SDL_WINDOWEVENT_MOVED)
        SDL_GetWindowPosition(e->img.win, (int *)&e->img.x, (int *)&e->img.y);

    if (e->event.window.event == SDL_WINDOWEVENT_RESIZED)
        window_resize(e);
}
