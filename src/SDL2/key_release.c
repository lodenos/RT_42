/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:50:18 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/14 16:08:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    key_release(t_env *e)
{
    if (e->event.key.keysym.sym == SDLK_UP)
        e->key.key_up = 0;
    else if (e->event.key.keysym.sym == SDLK_DOWN)
        e->key.key_down = 0;
    else if (e->event.key.keysym.sym == SDLK_RIGHT)
         e->key.key_right = 0;
    else if (e->event.key.keysym.sym == SDLK_LEFT)
       e->key.key_left = 0;
    else if (e->event.key.keysym.sym == 0)
        ft_putstr("Key : .\n");
    else if (e->event.key.keysym.sym == SDLK_COMMA)
        e->key.key_comma = 0;
    else if (e->event.key.keysym.sym == SDLK_w)
        e->key.key_w = 0;
    else if (e->event.key.keysym.sym == SDLK_s)
        e->key.key_s = 0;
    else if (e->event.key.keysym.sym == SDLK_SPACE)
        e->key.key_space = 0;
    else if (e->event.key.keysym.sym == SDLK_LSHIFT)
            ft_putstr("Key : left shift\n");
}
