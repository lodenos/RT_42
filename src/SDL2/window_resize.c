/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:54:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/29 16:38:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    window_resize(t_env *e)
{
    SDL_DestroyRenderer(e->img.rend);
    SDL_GetWindowSize(e->img.win, (int *)&e->img.w, (int *)&e->img.h);

    printf("W = %zu ; H = %zu\n", e->img.w, e->img.h);

    if (!(e->img.rend = SDL_CreateRenderer(e->img.win, -1,
                SDL_RENDERER_SOFTWARE)))
        ft_putstr_err(SDL_GetError(), 1);
    SDL_SetRenderDrawColor(e->img.rend, 0, 0, 0, 255);
    if (SDL_RenderClear(e->img.rend) != 0)
        ft_putstr_err(SDL_GetError(), 1);
    SDL_RenderPresent(e->img.rend);
    play_scene(e, e->img.rend);
}
