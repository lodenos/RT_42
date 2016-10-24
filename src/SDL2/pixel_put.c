/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:56:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:52:16 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void pixel_put(SDL_Renderer *rend, unsigned int color, size_t x, size_t y)
{
    SDL_SetRenderDrawColor(rend, (Uint8)(color >> 24), (Uint8)(color >> 16),
            (Uint8)(color >> 8), (Uint8)color);
    SDL_RenderDrawPoint(rend, (int)x, (int)y);
}
