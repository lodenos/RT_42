/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 00:36:27 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/16 10:36:25 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

#define FT_EXIT_SLAVE_CONNECTION    {--((t_slv *)arg)->e->nbr_slv;  \
                                    free(tmp);                      \
                                    close(((t_slv *)arg)->fds);     \
                                    free(arg);                      \
                                    pthread_exit(NULL);}

static inline void  exchange_data_of_host(t_slv *arg)
{
    unsigned int    *img;
    t_mem           m_img;
    t_mem           m_scn;
    t_mem           m_obj;
    t_mem           m_spt;

    m_spt = cluster_create_buffer(arg->fds, sizeof(t_spt));
    m_obj = cluster_create_buffer(arg->fds, sizeof(t_obj) *
            (arg->e->scn.n_obj + 1));
    m_scn = cluster_create_buffer(arg->fds, sizeof(t_scn) *
            (arg->e->scn.n_spt + 1));

    cluster_write_buffer(m_scn, (void *)&arg->e->scn);
    cluster_write_buffer(m_obj, (void *)arg->e->obj);
    cluster_write_buffer(m_spt, (void *)arg->e->spt);


    m_img = cluster_create_buffer(arg->fds, sizeof(unsigned int) *
            arg->e->scn.cam.h * arg->e->scn.cam.w);
    img = (unsigned int *)cluster_read_buffer(m_img);


    ft_putendl("-----> Teste");

    ft_putnbr(img[0]);

}

void                *slave_connection(void *arg)
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
