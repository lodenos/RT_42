/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:48:20 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 01:17:20 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void sdl_kp_2(t_env *e, cl_float3 *pos)
{
  pos->y -= 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}

void sdl_kp_4(t_env *e, cl_float3 *pos)
{
  pos->x -= 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}

void sdl_kp_6(t_env *e, cl_float3 *pos)
{
  pos->x += 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}

void sdl_kp_8(t_env *e, cl_float3 *pos)
{
  pos->y += 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}

void sdl_kp_plus(t_env *e, cl_float3 *pos)
{
  pos->z += 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}

void sdl_kp_minus(t_env *e, cl_float3 *pos)
{
  pos->z -= 100;
  /*create_window(e, SDL_WINDOW_RESIZABLE);*/
  printf("POS X: %f\nPOS Y: %f\nPOS Z: %f\n\n", pos->x, pos->y, pos->z);
}
