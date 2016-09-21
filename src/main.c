/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:01:15 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 17:29:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void init_RT(t_env *e)
{
    e->img.w = WIDTH;
    e->img.h = HEIGHT;
    e->img.x = SDL_WINDOWPOS_CENTERED;
    e->img.y = SDL_WINDOWPOS_CENTERED;
    e->img.win = NULL;
    e->img.rend = NULL;
    e->exit = 1;
    e->img.flags = 0;
}

int         main(int argc, char **argv)
{
    t_env  e;

    /*  lunch_opencl(&e.cl);    */
    parser(&e, argc, argv);
    if (SDL_Init(SDL_INIT_EVERYTHING))
        ft_putstr_err(SDL_GetError(), 1);
    init_RT(&e);
    create_window(&e, SDL_WINDOW_RESIZABLE);
    while (e.exit)
        event_everything(&e);
    return (0);
}
