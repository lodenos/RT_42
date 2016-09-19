/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:00:50 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/18 20:34:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    create_window(t_env *e, Uint32 flags)
{
    if (e->img.win != NULL)
        SDL_DestroyWindow(e->img.win);
    if (e->img.rend != NULL)
        SDL_DestroyRenderer(e->img.rend);
    if (!(e->img.win = SDL_CreateWindow(TITLE, e->img.x, e->img.y, e->img.w,
        e->img.h, flags)))
        ft_putstr_err(SDL_GetError(), 1);
    if (!(e->img.rend = SDL_CreateRenderer(e->img.win, -1,
        SDL_RENDERER_SOFTWARE)))
        ft_putstr_err(SDL_GetError(), 1);	
    SDL_SetRenderDrawColor(e->img.rend, 0, 0, 0, 255);
    if (SDL_RenderClear(e->img.rend))
        ft_putstr_err(SDL_GetError(), 1);
	play_scene(e, e->img.rend);
}
