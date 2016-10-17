/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:58:58 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/17 11:27:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline void  init_RT(t_env *e)
{
    init_keyboard(&e->key);
    init_mouse(&e->mouse);
    e->img.img = NULL;
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
    int     i;
    int     fd;
    char    *tmp;
    char    **src;

    i = 0;
    if ((fd = open("Make_CL", O_RDONLY)) == -1)
        ft_putstr_err("ERROR: Make_CL not found", 1);
    tmp = get_file_raw(fd);
    close(fd);
    src = ft_strsplit(tmp, '\n');
    if ((cl->nbr_src = ft_strlen_tab(src) - 1) < 2)
        ft_putstr_err("ERROR: src Make_CL < 2 args", 1);
    if (!(cl->flags = ft_strdup(src[0])))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(cl->file = (char **)ft_memalloc(sizeof(char *) * (cl->nbr_src + 1))))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(cl->size_src = (size_t *)ft_memalloc(sizeof(size_t) *
            (cl->nbr_src + 1))))
        ft_putstr_err("ERROR: malloc", 1);
    if (!(cl->src = (char **)ft_memalloc(sizeof(char *) * (cl->nbr_src + 1))))
        ft_putstr_err("ERROR: malloc", 1);
    while (src[++i] != NULL)
        if (!(cl->file[i - 1] = ft_strdup(src[i])))
            ft_putstr_err("ERROR: malloc", 1);
    free(tmp);
    free_tab((void **)src);
}

void    get_arg_main(t_env *e, int argc, char **argv)
{
    int     i;

    i = 0;
    e->gpu = 0;
    e->host = 0;
    e->slave = 0;
    if (argc < 2)
        ft_putstr_err("", 1);
    while (++i < argc)
    {
        if (strcmp(argv[i], "-gpu") == 0)
            e->gpu = 1;
        else if (strcmp(argv[i], "-host") == 0)
        {
            e->host = 1;
            e->slave = 0;
        }
        else if (strcmp(argv[i], "-slave") == 0)
        {
            e->host = 0;
            e->slave = 1;
        }
    }
}

int                 main(int argc, char **argv)
{
    t_env           e;
    pthread_t       pt_host;

    get_arg_main(&e, argc, argv);
    get_scene(&e, argv[1]);
    if (e.gpu)
    {
        init_file_opencl(&e.cl);
        lunch_opencl(&e.cl);
    }
    if (e.host)
        if (pthread_create(&pt_host, NULL, &host, NULL) == -1)
            ft_putstr_err("ERROR: thread", 1);
    if (e.slave)
        if (pthread_create(&pt_host, NULL, &host, NULL) == -1)
            ft_putstr_err("ERROR: thread", 1);
    if (SDL_Init(SDL_INIT_EVERYTHING))
        ft_putstr_err(SDL_GetError(), 1);
    init_RT(&e);
    create_window(&e, SDL_WINDOW_RESIZABLE);
    e.start = 1;
    play_scene(&e, e.img.rend);
    while (e.exit)
        event_everything(&e);
    return (0);
}
