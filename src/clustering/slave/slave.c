/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:25:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/16 10:39:13 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

#define FT_EXIT_SLAVE   {free(tmp); close(fds); pthread_exit(NULL);}

static inline void  exchange_data_of_slave(t_env *e, int fds)
{
    unsigned int    *img;
    t_mem           m_img;
    t_mem           m_scn;
    t_mem           m_obj;
    t_mem           m_spt;

    m_scn = cluster_create_buffer(fds, sizeof(t_scn));
    e->scn = *(t_scn *)cluster_read_buffer(m_scn);

    m_obj = cluster_create_buffer(fds, sizeof(t_obj) * (e->scn.n_obj + 1));
    m_spt = cluster_create_buffer(fds, sizeof(t_spt) * (e->scn.n_spt + 1));

    e->obj = (t_obj *)cluster_read_buffer(m_obj);
    e->spt = (t_spt *)cluster_read_buffer(m_spt);

    m_img = cluster_create_buffer(fds, sizeof(unsigned int) *
            e->scn.cam.h * e->scn.cam.w);



    img = (unsigned int *)ft_memalloc(sizeof(unsigned int) * e->scn.cam.h *
            e->scn.cam.w);
    img[0] = '@';

    cluster_write_buffer(m_img, (void *)img);
}

void    *slave(void *arg)
{
    int         fds;
    sockaddr_in sck;
    char        *tmp;

    if (!(tmp = (char *)ft_memalloc(sizeof(char) * 1025)))
        ft_putstr_err("ERROR: malloc", 1);
    if ((fds = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ft_putstr_err("ERROR: Socket fds", 1);
    sck.sin_addr.s_addr = inet_addr("127.0.0.1");
    sck.sin_family = AF_INET;
    sck.sin_port = htons(4297);
    if (connect(fds, (sockaddr *)&sck, sizeof(sck)) == -1)
    {
        ft_putendl("TCP: connect error");
        FT_EXIT_SLAVE
    }
    if (write(fds, VALID, 32) == -1)
    {
        ft_putendl("TCP: error write");
        FT_EXIT_SLAVE
    }
    if (read(fds, tmp, 32) == -1)
    {
        ft_putendl("TCP: error read");
        FT_EXIT_SLAVE
    }
    if (ft_strcmp(tmp, CONNECT))
    {
        ft_putendl(tmp);
        ft_putendl("Connection Error -- 127.0.0.1");
        FT_EXIT_SLAVE
    }
    ft_putendl("Connection Established -- 127.0.0.1");
    exchange_data_of_slave((t_env *)arg, fds);
    FT_EXIT_SLAVE
}
