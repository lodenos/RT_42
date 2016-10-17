/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:54:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/14 11:12:07 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    window_resize(t_env *e)
{
    free(e->img.img);
    SDL_DestroyRenderer(e->img.rend);
    SDL_GetWindowSize(e->img.win, (int *)&e->img.w, (int *)&e->img.h);
    e->scn.cam.w = e->img.w;
    e->scn.cam.h = e->img.h;
    if (!(e->img.rend = SDL_CreateRenderer(e->img.win, -1,
                SDL_RENDERER_SOFTWARE)))
        ft_putstr_err(SDL_GetError(), 1);
    if (!(e->img.img = (int *)ft_memalloc(sizeof(int) * e->img.w *
                e->img.h)))
        ft_putstr_err("ERROR: malloc error", 1);
    SDL_SetRenderDrawColor(e->img.rend, 0, 0, 0, 255);
    if (SDL_RenderClear(e->img.rend) != 0)
        ft_putstr_err(SDL_GetError(), 1);
    SDL_RenderPresent(e->img.rend);
}
