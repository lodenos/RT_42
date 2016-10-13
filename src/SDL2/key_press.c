/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:48:20 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 01:17:20 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  key_press_sub(t_env *e)
{
    if (e->event.key.keysym.sym == SDLK_s)
        ft_putstr("Key : s\n");
    else if (e->event.key.keysym.sym == SDLK_d)
        ft_putstr("Key : d\n");
    else if (e->event.key.keysym.sym == SDLK_a)
        ft_putstr("Key : a\n");
    else if (e->event.key.keysym.sym == SDLK_LSHIFT)
        ft_putstr("Key : left shift\n");
    else if (e->event.key.keysym.sym == SDLK_SPACE)
        ft_putstr("Key : space\n");
}

void    key_press(t_env *e)
{
    if (e->event.key.keysym.sym == SDLK_ESCAPE)
        e->exit = 0;
    else if (e->event.key.keysym.sym == SDLK_F1)
        create_window(e, SDL_WINDOW_SHOWN);
    else if (e->event.key.keysym.sym == SDLK_F2)
        create_window(e, SDL_WINDOW_RESIZABLE);
    else if (e->event.key.keysym.sym == SDLK_F10)
        create_window(e, SDL_WINDOW_FULLSCREEN_DESKTOP);
    else if ((e->event.key.keysym.sym == SDLK_UP) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_up = 1;
    else if ((e->event.key.keysym.sym == SDLK_DOWN) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_down = 1;
    else if ((e->event.key.keysym.sym == SDLK_RIGHT) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_right = 1;
    else if ((e->event.key.keysym.sym == SDLK_LEFT) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_left = 1;
    else if ((e->event.key.keysym.sym == 0) &&
            (e->event.key.state == SDL_PRESSED))
        ft_putstr("Key : .\n");
    else if ((e->event.key.keysym.sym == SDLK_COMMA) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_comma = 1;
    else if ((e->event.key.keysym.sym == SDLK_w) &&
            (e->event.key.state == SDL_PRESSED))
        e->key.key_w = 1;
  /**********************************************************/

    else if (e->event.key.keysym.sym == SDLK_KP_2)
          sdl_kp_2(e, &e->scn.cam.pos);
    else if (e->event.key.keysym.sym == SDLK_KP_4)
          sdl_kp_4(e, &e->scn.cam.pos);
    else if (e->event.key.keysym.sym == SDLK_KP_6)
          sdl_kp_6(e, &e->scn.cam.pos);
    else if (e->event.key.keysym.sym == SDLK_KP_8)
          sdl_kp_8(e, &e->scn.cam.pos);
    else if (e->event.key.keysym.sym == SDLK_KP_PLUS)
          sdl_kp_plus(e, &e->scn.cam.pos);
    else if (e->event.key.keysym.sym == SDLK_KP_MINUS)
          sdl_kp_minus(e, &e->scn.cam.pos);/*
    else if (e->event.type == SDL_MOUSEBUTTONDOWN)
    {
        if ((e->event.button.button == SDL_BUTTON_LEFT) && e->scn.obj[id].pos)
        {
            if (e->event.key.keysym.sym == SDLK_KP_2)
                sdl_kp_2(e, &e->scn.obj[id].pos.y);
            else if (e->event.key.keysym.sym == SDLK_KP_4)
                sdl_kp_4(e, &e->scn.obj[id].pos.x);
            else if (e->event.key.keysym.sym == SDLK_KP_6)
                sdl_kp_6(e, &e->scn.obj[id].pos.x);
            else if (e->event.key.keysym.sym == SDLK_KP_8)
                sdl_kp_8(e, &e->scn.obj[id].pos.y);
            else if (e->event.key.keysym.sym == SDLK_KP_PLUS)
                sdl_kp_plus(e, &e->scn.obj[id].pos.z);
            else if (e->event.key.keysym.sym == SDLK_KP_MINUS)
                sdl_kp_minus(e, &e->scn.obj[id].pos.z);
          }
      }*/

  /**********************************************************/
    else
        key_press_sub(e);
    create_window(e, SDL_WINDOW_RESIZABLE);
}
