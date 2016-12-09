/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:22:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 15:22:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	create_window(t_env *e, Uint32 flags)
{
	if (e->img.win != NULL)
		SDL_DestroyWindow(e->img.win);
	if (e->img.rend != NULL)
		SDL_DestroyRenderer(e->img.rend);
	if (e->img.img != NULL)
		free(e->img.img);
	if (!(e->img.win = SDL_CreateWindow(TITLE, (int)e->img.x, (int)e->img.y,
			(int)e->img.w, (int)e->img.h, flags)))
		ft_putstr_err(SDL_GetError(), 1);
	if (!(e->img.img = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
			e->img.w * e->img.h)))
		ft_putstr_err("ERROR: malloc error", 1);
	e->scn.cam.w = e->img.w;
	e->scn.cam.h = e->img.h;
	if (!(e->img.rend = SDL_CreateRenderer(e->img.win, -1,
			SDL_RENDERER_SOFTWARE)))
		ft_putstr_err(SDL_GetError(), 1);
	SDL_SetRenderDrawColor(e->img.rend, 0, 0, 0, 255);
	if (SDL_RenderClear(e->img.rend))
		ft_putstr_err(SDL_GetError(), 1);
	SDL_RenderPresent(e->img.rend);
}
