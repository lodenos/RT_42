/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 00:36:27 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:12 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

#define FT_EXIT_SLAVE_CONNECTION    {--((t_slv *)arg)->e->nbr_slv;  \
                                    free(tmp);                      \
                                    close(((t_slv *)arg)->fds);     \
                                    free(arg);                      \
                                    pthread_exit(NULL);}

static inline void          send_data(t_slv *arg, t_mimg mimg)
{
    t_mem           m_img;
    t_mem           m_mimg;
    t_mem           m_scn;
    t_mem           m_obj;
    t_mem           m_spt;

    m_spt = cluster_create_buffer(arg->fds, sizeof(t_spt));
    m_obj = cluster_create_buffer(arg->fds, sizeof(t_obj) *
            (arg->e->scn.n_obj + 1));
    m_scn = cluster_create_buffer(arg->fds, sizeof(t_scn) *
            (arg->e->scn.n_spt + 1));
    m_mimg = cluster_create_buffer(arg->fds, sizeof(t_mimg));
    cluster_write_buffer(m_scn, (void *)&arg->e->scn);
    cluster_write_buffer(m_mimg, (void *)&mimg);
    cluster_write_buffer(m_obj, (void *)arg->e->obj);
    cluster_write_buffer(m_spt, (void *)arg->e->spt);
}

static inline unsigned int  *recv_data(t_slv *arg)
{
    t_mem   m_img;

    m_img = cluster_create_buffer(arg->fds, sizeof(unsigned int) *
            arg->e->scn.cam.h * arg->e->scn.cam.w);
    return ((unsigned int *)cluster_read_buffer(m_img));

}

static inline t_mimg        get_range_work(t_env *e, size_t id, size_t max_bloc)
{
    t_mimg  mimg;

    mimg.start_x = (id * max_bloc) % e->scn.cam.w;
    mimg.start_y = (id * max_bloc) / e->scn.cam.w;
    ++id;
    mimg.stop_x = (id * max_bloc) % e->scn.cam.w;
    mimg.stop_y = (id * max_bloc) / e->scn.cam.w;
    return (mimg);
}

static inline void          exchange_data_of_host(t_slv *arg)
{
    size_t          id;
    t_mimg          mimg;

    _Bool           exit = 1;

    size_t          nbr_elem = arg->e->scn.cam.h * arg->e->scn.cam.w;
    size_t          max_bloc = 512;
    size_t          max_elem;
    unsigned int    *img_work;
    char            *tab_work;

    while (exit)
    {
        id = cluster_get_contribution(id, tab_work, arg->e->img, img_work, mimg);
        mimg = get_range_work(arg->e, id, max_bloc);
        send_data(arg, mimg);
        img_work = recv_data(arg);
        cluster_finish_contribution(id, tab_work, arg->e->img, img_work, mimg);
    }
}

void                        *slave_connection(void *arg)
{
    int     i;
    char    *tmp;

    i = 1;
    ++((t_slv *)arg)->e->nbr_slv;
    ft_putendl(inet_ntoa(((t_slv *)arg)->sck.sin_addr));
    if(!(tmp = (char *)ft_memalloc(sizeof(char) * 32)))
        ft_putstr_err("ERROR: malloc", 1);
    if (read(((t_slv *)arg)->fds, tmp, 32) == -1)
    {
        ft_putendl("TCP: error read");
        FT_EXIT_SLAVE_CONNECTION
    }
    if (ft_strcmp(tmp, VALID))
    {
        ft_putendl("Slave Invalid");
        FT_EXIT_SLAVE_CONNECTION
    }
    if (write(((t_slv *)arg)->fds, CONNECT, 32) == -1)
    {
        ft_putendl("TCP: error write");
        FT_EXIT_SLAVE_CONNECTION
    }
    exchange_data_of_host((t_slv *)arg);
    FT_EXIT_SLAVE_CONNECTION
}
