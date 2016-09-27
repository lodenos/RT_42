/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:58:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 23:02:35 by glodenos         ###   ########.fr       */
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

static inline void  init_file_opencl(t_opcl *cl)
{
    if (!(cl->file = (char **)ft_memalloc(sizeof(char *) * 2)))
        ft_putstr_err("ERROR: malloc", 1);
    cl->file[0] = ft_strdup("src_cl/run_raytracing.cl");
    cl->file[1] = NULL;
    cl->flags = NULL;
    if (!(cl->size_src = (size_t *)ft_memalloc(sizeof(size_t) * 2)))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(cl->src = (char **)ft_memalloc(sizeof(char *) * 2)))
        ft_putstr_err("ERROR: malloc", 1);
}

int                 main(int argc, char **argv)
{
    t_env   e;

    if (argc != 2)
        ft_putstr_err("RT: a single scene must be passed as argument", 1);
    get_scene(&e, argv[1]);
    init_file_opencl(&e.cl);
    lunch_opencl(&e.cl);
    if (SDL_Init(SDL_INIT_EVERYTHING))
        ft_putstr_err(SDL_GetError(), 1);
    init_RT(&e);
    create_window(&e, SDL_WINDOW_RESIZABLE);
    while (e.exit)
        event_everything(&e);
    return (0);
}
