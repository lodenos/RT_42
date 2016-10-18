/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 11:47:37 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/18 16:38:16 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void push_to_window(SDL_Renderer *rend, int *img, size_t w, size_t h)
{
    register int    k;
    register int    x;
    register int    y;

    x = -1;
    while (++x < w)
    {
        y = -1;
        while (++y < h)
        {
            k = x + y * w;
            SDL_SetRenderDrawColor(rend, (unsigned char)(img[k] >> 24),
                    (unsigned char)(img[k] >> 16), (unsigned char)(img[k] >> 8),
                    (unsigned char)(img[k]));
            SDL_RenderDrawPoint(rend, x, y);
        }
    }
}
