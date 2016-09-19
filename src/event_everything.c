/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 10:44:34 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/18 20:34:25 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void	ft_SDL_KEYDOWN(t_env *e)
{
    if (e->event.key.keysym.sym == SDLK_ESCAPE)
        e->exit = 0;
    else if (e->event.key.keysym.sym == SDLK_F1)
        create_window(e, SDL_WINDOW_SHOWN);
    else if (e->event.key.keysym.sym == SDLK_F2)
        create_window(e, SDL_WINDOW_RESIZABLE);
    else if (e->event.key.keysym.sym == SDLK_F10)
        create_window(e, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void    event_everything(t_env *e)
{
    SDL_WaitEvent(&e->event);
    if (e->event.type == SDL_KEYDOWN)
        ft_SDL_KEYDOWN(e);
    if (e->event.window.event == SDL_WINDOWEVENT_CLOSE)
        e->exit = 0;
    if (e->event.window.event == SDL_WINDOWEVENT_MOVED)
        SDL_GetWindowPosition(e->img.win, &e->img.x, &e->img.y);
    if (e->event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        SDL_GetWindowSize(e->img.win, &e->img.w, &e->img.h);
        SDL_DestroyRenderer(e->img.rend);
        if (!(e->img.rend = SDL_CreateRenderer(e->img.win, -1,
                        SDL_RENDERER_SOFTWARE)))
            ft_putstr_err(SDL_GetError(), 1);
        SDL_SetRenderDrawColor(e->img.rend, 0, 0, 0, 255);
        if (SDL_RenderClear(e->img.rend) != 0)
            ft_putstr_err(SDL_GetError(), 1);
        play_scene(e, e->img.rend);
    }
}
