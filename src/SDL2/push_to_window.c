/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 11:47:37 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/17 12:35:42 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void push_to_window(SDL_Renderer *rend, int *img, size_t w, size_t h)
{
    size_t  k;
    size_t  x;
    size_t  y;

    x = 0;
    while (x < w)
    {
        y = 0;
        while (y < h)
        {
            k = x + y * w;
            pixel_put(rend, (t_rgba){(unsigned char)(img[k] >> 24),
                    (unsigned char)(img[k] >> 16), (unsigned char)(img[k] >> 8),
                    (unsigned char)(img[k])}, x, y);
            ++y;
        }
        ++x;
    }
}
