/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:56:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 00:05:41 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void pixel_put(SDL_Renderer *rend, t_rgba rgba, size_t x, size_t y)
{
    SDL_SetRenderDrawColor(rend, (Uint8)rgba.red, (Uint8)rgba.green,
            (Uint8)(rgba.blue), (Uint8)rgba.alpha);
    SDL_RenderDrawPoint(rend, (int)x, (int)y);
}
