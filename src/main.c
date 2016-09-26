/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:58:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 16:45:48 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_RT(t_env *e)
{
    e->img.h = HEIGHT;
    e->img.w = WIDTH;
    e->img.x = SDL_WINDOWPOS_CENTERED;
    e->img.y = SDL_WINDOWPOS_CENTERED;
    e->img.win = NULL;
    e->img.rend = NULL;
    e->exit = 1;
    e->img.flags = 0;
}

int                 main(int argc, char **argv)
{
    t_env   e;

    if (argc != 2)
        ft_putstr_err("RT: a single scene must be passed as argument", 1);
    get_scene(&e, argv[1]);
/*    lunch_opencl(&e.cl);*/
    if (SDL_Init(SDL_INIT_EVERYTHING))
        ft_putstr_err(SDL_GetError(), 1);
    init_RT(&e);
    create_window(&e, SDL_WINDOW_RESIZABLE);
    while (e.exit)
        event_everything(&e);
    return (0);
}
