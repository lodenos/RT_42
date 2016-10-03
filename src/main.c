/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:58:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/03 16:35:53 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_RT(t_env *e)
{
    init_keyboard(&e->key);
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
    cl->nbr_src = 2;
    if (!(cl->file = (char **)ft_memalloc(sizeof(char *) * cl->nbr_src + 1)))
        ft_putstr_err("ERROR: malloc", 1);
    cl->file[0] = ft_strdup("src_cl/ray_tracing/run_raytracing.cl");
    cl->file[1] = ft_strdup("src_cl/object/sphere.cl");
    cl->file[2] = NULL;
    cl->flags = ft_strdup("-I ./head_cl");
    if (!(cl->size_src = (size_t *)ft_memalloc(sizeof(size_t) * 2)))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(cl->src = (char **)ft_memalloc(sizeof(char *) * 2)))
        ft_putstr_err("ERROR: malloc", 1);
}

int                 main(int argc, char **argv)
{
    t_env   e;

    e.GPU = 0;
    if (argc < 2 || argc > 3)
        ft_putstr_err("RT: a single scene must be passed as argument", 1);
    if (argc == 3)
        if ((e.GPU = ft_atoi(argv[2])) < 0 || e.GPU > 1)
            ft_putstr_err("ERROR: main.argument GPU: 1 == on ; 2 == off", 1);
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
